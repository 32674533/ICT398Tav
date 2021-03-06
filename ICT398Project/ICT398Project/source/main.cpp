
		/** main.cpp - main file for collision project
        * @class Date class
        * @brief contains all code relating to building the world/collisions
		* @TODO move all collision related and load related code out of main and into another file/object, fix lighting
        * @author Ben Porter
        * modified 16/09/2017
		* @bugs collisions with back wall of tavern cause camera to get stuck
        */

#include <irrlicht.h>
#include <driverChoice.h>
#include "GameObject.h"
#include "MyEventReceiver.h"
#include "physics/Types.h"
//this is here for in the future in case implementation of bullet is needed
#include "../bullet3-2.86.1/src/btBulletCollisionCommon.h"
#include "../bullet3-2.86.1/src/btBulletDynamicsCommon.h"
//remove this, purely here for testing
#include "FCM.h"
#include "Miner.h"
#include <map>
using namespace irr;

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif
//have no idea why I need this but camera plays up if I don't have it
enum
{
};


int main()
{
	// Variables for physics
	types::Vector3D camPosVec, camTargetVec, camLookAt;

	// Bullet setup
	btCollisionConfiguration* collisionConfig;
	btCollisionDispatcher* dispatch;
	btBroadphaseInterface* broadphase;
	btCollisionWorld* collisionWorld;
	//use this to store all the objects in the game world
	//use worldObjects.size() to get how many objects there are
	std::map<int, GameObject&> worldObjects;
	double collisionWorldSize = 300;
	unsigned int maxCollisionObjs = 200; // Just giving a semi-reasonable limit
	float count=0; //keeps track of milliseconds since last cycle
	float maxCount = 200; //how often you want AI logic to update, is in milliseconds
	btVector3 worldAABBMax((btScalar)collisionWorldSize, (btScalar)collisionWorldSize, (btScalar)collisionWorldSize),
			  worldAABBMin(-(btScalar)collisionWorldSize, -(btScalar)collisionWorldSize, -(btScalar)collisionWorldSize);
	//removethis ************************************************
	
	collisionConfig = new btDefaultCollisionConfiguration();
	dispatch = new btCollisionDispatcher(collisionConfig);
	broadphase = new bt32BitAxisSweep3(worldAABBMin, worldAABBMax, maxCollisionObjs, 0, true);
	collisionWorld = new btCollisionWorld(dispatch, broadphase, collisionConfig);
	//////End of bullet stuff
	// create device
    MyEventReceiver receiver;

	//Irrlicht gives us a variety of devices to choose from, we are using openGL
	//device type, window size, bits per pixel in fullscreen fullscreen or not
	IrrlichtDevice *device = createDevice(video::EDT_OPENGL, core::dimension2d<irr::u32>(1280, 720), 16, false, false, false, &receiver);
	scene::IMetaTriangleSelector* mainTriangleSelector = 0;
	if (device == 0)
		return 1; // could not create selected driver.

	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();

	//mainTriangleSelector = smgr->createMetaTriangleSelector();
	//scene::ITriangleSelector* s = 0; 
	scene::ITriangleSelector* selector = 0;
	
	//if we have time, get rid of this and make our own camera controls, default ones are super weird, j = jump, arrow keys to move
	//wasd navigation
	SKeyMap keyMap[8];

	keyMap[1].Action = EKA_MOVE_FORWARD;
	keyMap[1].KeyCode = KEY_KEY_W;

	keyMap[3].Action = EKA_MOVE_BACKWARD;
	keyMap[3].KeyCode = KEY_KEY_S;

	keyMap[5].Action = EKA_STRAFE_LEFT;
	keyMap[5].KeyCode = KEY_KEY_A;

	keyMap[7].Action = EKA_STRAFE_RIGHT;
	keyMap[7].KeyCode = KEY_KEY_D;

	//fps cam
	scene::ICameraSceneNode* camera = 
		smgr->addCameraSceneNodeFPS(0, 100.0f, .1f, 0, keyMap, 8, true, 3.f);

	//scene::ICameraSceneNode* camera =
		//smgr->addCameraSceneNodeFPS(0, 100.0f, .1f, 0, 0, true, 3.f);
	camera->setPosition(core::vector3df(-100,50,50));
	camera->setTarget(core::vector3df(-70,30,-60));
	
	//gets rid of mouse cursor
	device->getCursorControl()->setVisible(false);

	

	// The loading of the actual model
	scene::IAnimatedMeshSceneNode* node = 0;
	//GameObject(io::path model, float x, float y, float z, scene::ISceneManager* smgr, scene::IAnimatedMeshSceneNode* node);
	//from starting position towards you is -x, right is -z

	//GAME OBJECT CREATION/AGENT  CREATION
	GameObject t1("../dependencies/models/cube.3ds", -80, 0, -60, 10, smgr, collisionWorld, device);
	t1.SetAfford(true, true, 10.0f, 0);
	//this is our agent game Object
	GameObject t2("../dependencies/models/cube.3ds", -80, 0, -200, 10, smgr, collisionWorld, device);
	t2.SetAfford(false, true, 80.0f, 30);
	GameObject t3("../dependencies/models/cone.3ds", -80, 0, 0, 5, smgr, collisionWorld, device);
	t3.SetAfford(false, true, 40.0f, 0);
	worldObjects.insert(std::make_pair(0, t1));
	worldObjects.insert(std::make_pair(1, t2));
	worldObjects.insert(std::make_pair(2, t3));
	//worldObjects[0] = t1;
	//worldObjects[1] = t2;
	//worldObjects[2] = t3;
	//Our Agent, the number is just it's ID, would come into play if we had lots of agents, otherwise it's kinda pointless
	Miner miner(1);
	miner.MinerCreateBody(t2);
	miner.SetWorldObjects(&worldObjects);
	//this is important for the agent update cycles
	//u32 time
	//irr::u32 time = device->getTimer()->getTime();
	float DeltaTime=0;
	float time=0;
	
	//t1.setScale(0.001);
	//GameObject t2;

	
	node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("../dependencies/models/Tavern.3ds"), 0);
	 //sets the location of the model
	node->setPosition(core::vector3df(0,-20,0));
	//node->setScale(core::vector3df(0.8f));
	node->getMaterial(0).NormalizeNormals = true;
	node->getMaterial(0).Lighting = true;
	//selector = smgr->createTriangleSelector(node);
	node->setTriangleSelector(selector);
	//selector->drop();
	//node->setAnimationSpeed(20.f);
	
	// Loading of Splash Screen
	video::ITexture* images = driver->getTexture("../dependencies/textures/SplashScreen.png");
    driver->makeColorKeyTexture(images, core::position2d<irr::s32>(0,0));
	bool SplashScreenCheck = false;

	if (node)
	{	
		selector = smgr->createOctreeTriangleSelector(
				node->getMesh(), node, 128);
	}

	
		if (selector)
	{
		//irrilichts collision handling method, selector is the triangle meshes, camera is the player camera
		//core::vector3df(5,5,5) is the sphere surrounding the camera x, z are width/length, y is height
		//core::vector3df(0,-10,0) is gravity, set at -10, can be changed
		//core::vector3df(0,13,0)); the point at which the sphere is created around
		scene::ISceneNodeAnimator* anim1 = smgr->createCollisionResponseAnimator(
			selector, camera, core::vector3df(5,5,5),
			core::vector3df(0,-10,0), core::vector3df(0,13,0));
		selector->drop(); // Drop selector when done
		camera->addAnimator(anim1);
		anim1->drop();  // drop the animator when done referring to it.
	}
	

	// Add a light
	//currently set at 0, 600, 0 need to find a better point to set it as things are really dark atm
	scene::ILightSceneNode * light = smgr->addLightSceneNode(0, core::vector3df(0,600,0),
		video::SColorf(1.0f,1.0f,1.0f,1.0f), 600.0f);

	int lastFPS = -1;
	//simulation loop

	int ted =0;
	
	while(device->run())
	if (device->isWindowActive())
	{
		//New experimental stuff - Alfie
		// Camera position as physics vector
		//printf("%u\n", time);
		DeltaTime = device->getTimer()->getTime() - time;
		 time = device->getTimer()->getTime();
		 count +=DeltaTime;
		 if(count >= maxCount){
			 //update Agents
			 miner.Update();
			 count =0;
		 }
		//printf("%e\n", DeltaTime);
		
		camPosVec.x = (float)camera->getPosition().X;
		camPosVec.y = (float)camera->getPosition().Y;
		camPosVec.z = (float)camera->getPosition().Z;

		// Camera target as physics vector
		camTargetVec.x = (float)camera->getTarget().X;
		camTargetVec.y = (float)camera->getTarget().Y;
		camTargetVec.z = (float)camera->getTarget().Z;

		// Look-at unit vector derived from above two
		camLookAt = (camTargetVec - camPosVec).normalise();

		driver->beginScene(true, true, 0);
		smgr->drawAll();
		// We're all done drawing, so end the scene.
		int numManifolds = collisionWorld->getDispatcher()->getNumManifolds();
		//FUZZY THINGY TEST METHOD
		//_+_++_+_++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		for (int i = 0; i < numManifolds; i++) {
			btPersistentManifold* contactManifold = collisionWorld->getDispatcher()->getManifoldByIndexInternal(i);
			btCollisionObject* obA = (btCollisionObject*)(contactManifold->getBody0());
			btCollisionObject* obB = (btCollisionObject*)(contactManifold->getBody1());
			contactManifold->refreshContactPoints(obA->getWorldTransform(), obB->getWorldTransform());
			int numContacts = contactManifold->getNumContacts();
    //For each contact point in that manifold
			for (int j = 0; j < numContacts; j++) {
			  //Get the contact information
				btManifoldPoint& pt = contactManifold->getContactPoint(j);
				//so this works out the position of the two points of collision as well as the distance between them?
				btVector3 ptA = pt.getPositionWorldOnA();
				btVector3 ptB = pt.getPositionWorldOnB();
				double ptdist = pt.getDistance();
			}
		}

		if(receiver.IsKeyDown(irr::KEY_KEY_X))
		{
			SplashScreenCheck = true;
		}
		if (SplashScreenCheck == true)
		{
			driver->draw2DImage(images, core::position2d<irr::s32>(300,50),
			core::rect<irr::s32>(0,0,600,600), 0,
			video::SColor(255,255,255,255), true);
			if(receiver.IsKeyDown(irr::KEY_LBUTTON))
			{
				exit(0);
			}
		}
		driver->endScene();
		//remove this code after we get splash screen working
		//int fps = driver->getFPS();
		if(count >= maxCount){
			//call update agent
			miner.Update();
			
		}
		//if (lastFPS != fps)
		//{
			core::stringw str = L"Collision detection example - Irrlicht Engine [";
			str += driver->getName();
			//str += "] FPS:";
			//str += fps;
			// testing camera look-at
			str += ", Camera look-at: (";
			str += camLookAt.x;
			str += ", ";
			str += camLookAt.y;
			str += ", ";
			str += camLookAt.z;
			str += "), Cube point mass: ";
			str += t1.getPointMass();
			str += "kg, Cone point mass: ";
			str += t3.getPointMass();
			str += "kg";

			device->setWindowCaption(str.c_str());
			//lastFPS = fps;
		//}
		
	}

	device->drop();

	return 0;
}

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
using namespace irr;

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif
//have no idea why I need this but camera plays up if I don't have it
enum
{
};

	float anger=0.9f;
	float joy=0.3f;
	float trust=0.4f;
	float anticipation=0.1f;
	float fear=0.1f;
	float surprise=0.9f;
	float sadness=0.7f;
	float disgust=0.6f;
	FCM map;

void FCMInit(){

	map.FillMatrixB(0, 0, joy);
	map.FillMatrixB(0, 1, trust);
	map.FillMatrixB(0, 2, fear);
	map.FillMatrixB(0, 3, surprise);
	map.FillMatrixB(0, 4, sadness);
	map.FillMatrixB(0, 5, disgust);
	map.FillMatrixB(0, 6, anger);
	map.FillMatrixB(0, 7, anticipation);
	//ones through the middle are 0 ie, emotions have no effect on themselves
	map.FillMatrixA(0, 0, 0);
	map.FillMatrixA(1, 1, 0);
	map.FillMatrixA(2, 2, 0);
	map.FillMatrixA(3, 3, 0);
	map.FillMatrixA(4, 4, 0);
	map.FillMatrixA(5, 5, 0);
	map.FillMatrixA(6, 6, 0);
	map.FillMatrixA(7, 7, 0);

	//BELOW NEEDS THEIR IMPACTS ON EACH OTHER FILLED OUT
	//joy
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(0, 1, 0.5);
	map.FillMatrixA(0, 2, 0);
	map.FillMatrixA(0, 3, -0.5);
	map.FillMatrixA(0, 4, -1);
	map.FillMatrixA(0, 5, -0.25);
	map.FillMatrixA(0, 6, 0);
	map.FillMatrixA(0, 7, 0.5);

	//trust
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(1, 0, 0.5);
	map.FillMatrixA(1, 2, 0.5);
	map.FillMatrixA(1, 3, 0);
	map.FillMatrixA(1, 4, -0.5);
	map.FillMatrixA(1, 5, -1);
	map.FillMatrixA(1, 6, -0.5);
	map.FillMatrixA(1, 7, 0);
	
	//fear
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(2, 0, 0);
	map.FillMatrixA(2, 1, 0.5);
	map.FillMatrixA(2, 3, 0.5);
	map.FillMatrixA(2, 4, 0);
	map.FillMatrixA(2, 5, -0.5);
	map.FillMatrixA(2, 6, -1);
	map.FillMatrixA(2, 7, -0.5);

	//surprise
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(3, 0, -0.5);
	map.FillMatrixA(3, 1, 0);
	map.FillMatrixA(3, 2, 0.5);
	map.FillMatrixA(3, 4, 0.5);
	map.FillMatrixA(3, 5, 0);
	map.FillMatrixA(3, 6, -0.5);
	map.FillMatrixA(3, 7, -1);

	//sadness
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(4, 0, -1);
	map.FillMatrixA(4, 1, -0.5);
	map.FillMatrixA(4, 2, 0);
	map.FillMatrixA(4, 3, 0.5);
	map.FillMatrixA(4, 5, 0.5);
	map.FillMatrixA(4, 6, 0);
	map.FillMatrixA(4, 7, -0.5);

	//disgust
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(5, 0, -0.5);
	map.FillMatrixA(5, 1, -1);
	map.FillMatrixA(5, 2, -0.5);
	map.FillMatrixA(5, 3, 0);
	map.FillMatrixA(5, 4, 0.5);
	map.FillMatrixA(5, 6, 0.5);
	map.FillMatrixA(5, 7, 0);

	//anger
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(6, 0, 0);
	map.FillMatrixA(6, 1, -0.5);
	map.FillMatrixA(6, 2, -1);
	map.FillMatrixA(6, 3, -0.5);
	map.FillMatrixA(6, 4, 0);
	map.FillMatrixA(6, 5, 0.5);
	map.FillMatrixA(6, 7, 0.5);

	//anticipation
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(7, 0, 0.5);
	map.FillMatrixA(7, 1, 0);
	map.FillMatrixA(7, 2, 0.5);
	map.FillMatrixA(7, 3, -1);
	map.FillMatrixA(7, 4, -0.5);
	map.FillMatrixA(7, 5, 0);
	map.FillMatrixA(7, 6, -0.5);
}


void FCMTest(){
	

	
	
	//filling the emotion matrix
	
	
	map.NewMatrix();

	joy =map.GetMatrixB(0, 0);
	trust = map.GetMatrixB(0, 1);
	fear = map.GetMatrixB(0, 2);
	surprise = map.GetMatrixB(0, 3);
	sadness = map.GetMatrixB(0, 4);
	disgust = map.GetMatrixB(0, 5);
	anger = map.GetMatrixB(0, 6);
	anticipation = map.GetMatrixB(0, 7);
			printf("%f\n", anger);
	printf("%f\n", joy);
	printf("%f\n", trust);
	printf("%f\n", anticipation);
	printf("%f\n", fear);
	printf("%f\n", surprise);
	printf("%f\n", sadness);
	printf("%f\n", disgust);
	printf("New cycle\n");
}


int main()
{
	// Variables for physics
	types::Vector3D camPosVec, camTargetVec, camLookAt;

	// Bullet setup
	btCollisionConfiguration* collisionConfig;
	btCollisionDispatcher* dispatch;
	btBroadphaseInterface* broadphase;
	btCollisionWorld* collisionWorld;
	double collisionWorldSize = 300;
	unsigned int maxCollisionObjs = 200; // Just giving a semi-reasonable limit

	btVector3 worldAABBMax((btScalar)collisionWorldSize, (btScalar)collisionWorldSize, (btScalar)collisionWorldSize),
			  worldAABBMin(-(btScalar)collisionWorldSize, -(btScalar)collisionWorldSize, -(btScalar)collisionWorldSize);
	//removethis ************************************************
	FCMInit();
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
	GameObject t1("../dependencies/models/cube.3ds", -80, 0, -60, 10, smgr, collisionWorld);
	GameObject t2("../dependencies/models/cube.3ds", -80, 0, -200, 10, smgr, collisionWorld);
	GameObject t3("../dependencies/models/cone.3ds", -80, 0, 0, 5, smgr, collisionWorld);
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
		//if(ted<100){
			FCMTest();
		//	ted++;
		//}
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
		int fps = driver->getFPS();
		
		//if (lastFPS != fps)
		//{
			core::stringw str = L"Collision detection example - Irrlicht Engine [";
			str += driver->getName();
			str += "] FPS:";
			str += fps;
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
			lastFPS = fps;
		//}
		
	}

	device->drop();

	return 0;
}
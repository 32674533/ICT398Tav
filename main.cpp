
		/** main.cpp - main file for collision project
        * @class Date class
        * @brief contains all code relating to building the world/collisions
		* @TODO move all collision related and load related code out of main and into another file/object, fix lighting
        * @author Ben Porter
        * modified 16/09/2017
		* @bugs collisions with back wall of tavern cause camera to get stuck
        */

#include <irrlicht.h>
//#include "driverChoice.h"
//this is here for in the future in case implementation of bullet is needed
//#include "btBulletCollisionCommon.h"
//#include "btBulletDynamicsCommon.h"
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
	//Irrlicht gives us a variety of devices to choose from, we are using openGL
	//device type, window size, bits per pixel in fullscreen fullscreen or not
	IrrlichtDevice *device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(640, 480), 16, false);
	scene::IMetaTriangleSelector* mainTriangleSelector = 0;
	if (device == 0)
		return 1; // could not create selected driver.

	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();
	//mainTriangleSelector = smgr->createMetaTriangleSelector();
	//scene::ITriangleSelector* s = 0; 
	scene::ITriangleSelector* selector = 0;
	
	//if we have time, get rid of this and make our own camera controls, default ones are super weird, j = jump, arrow keys to move
	scene::ICameraSceneNode* camera =
		smgr->addCameraSceneNodeFPS(0, 100.0f, .1f, 0, 0, true, 3.f);
	camera->setPosition(core::vector3df(-100,50,50));
	camera->setTarget(core::vector3df(-70,30,-60));
	
	//gets rid of mouse cursor
	device->getCursorControl()->setVisible(false);
	
	

	// The loading of the actual model
	scene::IAnimatedMeshSceneNode* node = 0;

	node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("../dependencies/models/Tavern.3ds"), 0);
	 //sets the location of the model
	node->setPosition(core::vector3df(0,-20,0));
	//node->setScale(core::vector3df(0.8f));
	node->getMaterial(0).NormalizeNormals = true;
	node->getMaterial(0).Lighting = true;
	selector = smgr->createTriangleSelector(node);
	node->setTriangleSelector(selector);
	selector->drop();
	//node->setAnimationSpeed(20.f);
	

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
	while(device->run())
	if (device->isWindowActive())
	{
		driver->beginScene(true, true, 0);
		smgr->drawAll();
		// We're all done drawing, so end the scene.
		driver->endScene();
		//remove this code after we get splash screen working
		int fps = driver->getFPS();
		
		if (lastFPS != fps)
		{
			core::stringw str = L"Collision detection example - Irrlicht Engine [";
			str += driver->getName();
			str += "] FPS:";
			str += fps;

			device->setWindowCaption(str.c_str());
			lastFPS = fps;
		}
		
	}

	device->drop();

	return 0;
}
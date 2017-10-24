#pragma once
/**
* @brief Gameobject class for all objects in the world
* @author Ben Porter
* @bug 90% sure i'm doing the model loading wrong, hoow do we change the model's position after initialisation?
*/

#include <string>
#include "affordance.h"
#include <irrlicht.h>
#include <driverChoice.h>
#include "Agent.h"
using namespace irr;
#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif
class GameObject
{
//weird variable types are due to irrilicht being weird and only accepting irrilicht defined types in a bunch of their methods
public:
	GameObject(void);
	GameObject(io::path model, float x, float y, float z, scene::ISceneManager* smgr);
	void setScale(float scal);
	void setPos(float x, float y, float z);
	~GameObject(void);
	float getPosx();
	float getPosy();
	float getPosz();
	scene::IAnimatedMeshSceneNode* GetNode();

private:
	io::path modelFile;
	float xPos, yPos, zPos;
	float scale;
	affordance affVect[10];
	scene::IAnimatedMeshSceneNode* node;
};



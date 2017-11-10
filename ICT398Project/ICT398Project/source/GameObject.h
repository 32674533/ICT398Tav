#pragma once
/**
* @brief Gameobject class for all objects in the world
* @class GameObject class
* @author Ben Porter
* @todo Create overloaded operators for =
* @todo make text appearing above model head actually work
*/

#include <string>
#include "affordance.h"
#include <irrlicht.h>
#include <driverChoice.h>
//#include "Agent.h"
#include "../bullet3-2.86.1/src/btBulletCollisionCommon.h"
#include "../bullet3-2.86.1/src/btBulletDynamicsCommon.h"
using namespace irr;
#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif
class GameObject
{
//weird variable types are due to irrilicht being weird and only accepting irrilicht defined types in a bunch of their methods
public:
		/**
        *@brief default constructor for GameObject
        */
	GameObject(void);
		/**
        *@brief overloaded constructor for GameObject
        *@param model - io::path, x -float, y -float, z - float, initMass -float, smgr - scene::ISceneManager*, colWorld - btCollisionWorld*, devic - IrrlichtDevice
        */
	GameObject(io::path model, float x, float y, float z, float initMass, scene::ISceneManager* smgr, btCollisionWorld* colWorld, IrrlichtDevice *devic);
		/**
        *@brief sets scale of GameObject
        *@param scal - float
        *@return void
        */
	void setScale(float scal);
		/**
        *@brief sets position of object in world
        *@param x- float, y - float, z - float
        *@return void
        */
	void setPos(float x, float y, float z);
		/**
        *@brief default deconstructor for GameObject
        */
	~GameObject(void);
		/**
        *@brief getter for xPos
        *@return float
        */
	float getPosx();
		/**
        *@brief getter for yPos
        *@return float
        */
	float getPosy();
		/**
        *@brief getter for zPos
        *@return float
        */
	float getPosz();
		/**
        *@brief getter for mass
        *@return float
        */
	float getMass(){return mass;};
		/**
        *@brief getter for pointMass
        *@return float
        */
	float getPointMass(){return pointMass;};
		/**
        *@brief getter for node
        *@return scene::IAnimatedMeshSceneNode*
        */
	scene::IAnimatedMeshSceneNode* GetNode();
		/**
        *@brief getter for afford
        *@return afford - affordance
        */
	affordance GetAfford();
		/**
        *@brief stes affordances
        *@param sit - bool, pick - bool, weight - float, str -int
        *@return void
        */
	void SetAfford(bool sit, bool pick, float weight, int str);
		/**
        *@brief incomplete, meant to display image above GameObject
        *@return void
        */
	void MakeTextBox();
private:
	io::path modelFile;
	float xPos, yPos, zPos;
	float scale;
	float mass, pointMass; // Masses in kilograms
	//affordance affVect[10];
	affordance afford;
	scene::IAnimatedMeshSceneNode* node;
	scene::ISceneManager* smg;
	btCollisionObject* collider;
	IrrlichtDevice *device;
};
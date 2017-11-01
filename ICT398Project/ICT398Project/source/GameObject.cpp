#include "GameObject.h"


GameObject::GameObject(void)
{
}

GameObject::GameObject(io::path model, float x, float y, float z, float initMass, scene::ISceneManager* smgr, btCollisionWorld* colWorld)
{
	modelFile = model;
	xPos = x;
	yPos = y;
	zPos = z;
	mass = initMass;
	//scale = scal;
	//io::path test = model;
	node = 0;
	node = smgr->addAnimatedMeshSceneNode(smgr->getMesh(modelFile), 0);
	node->setPosition(core::vector3df(xPos,yPos,zPos)); // Why does this line cause the game to crash?
	//node->setScale(core::vector3df(2000.0f));
	node->getMaterial(0).NormalizeNormals = true;
	node->getMaterial(0).Lighting = true;

	// Point mass setup
	int numPoints = (int)node->getMesh()->getMeshBuffer(0)->getIndexCount();
	pointMass = mass / (float)numPoints;

	// Bullet stuff
	collider = new btCollisionObject();
	collider->getWorldTransform().setOrigin(btVector3((btScalar)xPos, (btScalar)yPos, (btScalar)zPos));
	collider->setCollisionShape(new btBoxShape(btVector3((btScalar)(node->getTransformedBoundingBox().getExtent().X / 2), (btScalar)(node->getTransformedBoundingBox().getExtent().Y / 2),
														 (btScalar)(node->getTransformedBoundingBox().getExtent().Z / 2))));
	colWorld->addCollisionObject(collider);
}

void GameObject::setScale(float scal){
	scale = scal;
	node->setScale(core::vector3df(0.8f));


}

GameObject::~GameObject(void)
{
}

float GameObject::getPosx(){
	return xPos;
}
float GameObject::getPosy(){
	return yPos;
}
float GameObject::getPosz(){
	return zPos;
}

scene::IAnimatedMeshSceneNode* GameObject::GetNode(){
	return node;
}

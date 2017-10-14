#include "GameObject.h"


GameObject::GameObject(void)
{
}

GameObject::GameObject(io::path model, float x, float y, float z, float scal, scene::ISceneManager* smgr, scene::IAnimatedMeshSceneNode* node)
{
	modelFile = model;
	xPos = x;
	yPos = y;
	zPos = z;
	scale = scal;
	//smgr->getmesh
	//io::path test = model;
	//scene::IAnimatedMeshSceneNode* node = 0;
	node = smgr->addAnimatedMeshSceneNode(smgr->getMesh(modelFile), 0);
	node->setPosition(core::vector3df(xPos,yPos,zPos));
	node->setScale(core::vector3df(2000.0f));
	node->getMaterial(0).NormalizeNormals = true;
	node->getMaterial(0).Lighting = true;
}

void GameObject::setScale(float scal, scene::IAnimatedMeshSceneNode* node){
	scale = scal;
	//node->setScale(core::vector3df(0.8f));


}

GameObject::~GameObject(void)
{
}

#include "GameObject.h"


GameObject::GameObject(void)
{
}

GameObject::GameObject(io::path model, float x, float y, float z, float initMass, scene::ISceneManager* smgr, btCollisionWorld* colWorld, IrrlichtDevice *devic)
{
	modelFile = model;
	xPos = x;
	yPos = y;
	zPos = z;
	mass = initMass;
	smg = smgr;
	device = devic;
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

void GameObject::setPos(float x, float y, float z){
	xPos =x;
	yPos =y;
	zPos =z;
	node->setPosition(core::vector3df(xPos,yPos,zPos));
}

affordance GameObject::GetAfford(){
	return afford;
}

void GameObject::SetAfford(bool sit, bool pick, float weight, int str){
	afford.SetPickUp(pick);
	afford.SetSit(sit);
	afford.SetWeight(weight);
	afford.SetStrength(str);
}


//work in progress - may resort to displaying an image instead
void GameObject::MakeTextBox(){
	//video::ITexture* images = smgr->getTexture("../dependencies/textures/SplashScreen.png");
    //driver->makeColorKeyTexture(images, core::position2d<irr::s32>(0,0));
	gui::IGUIFont* font = device->getGUIEnvironment()->getBuiltInFont();
	font->draw(L"This demo shows that Irrlicht is also capable of drawing 2D graphics.",
		core::rect<s32>(xPos,yPos,xPos+50,yPos+50),
                    video::SColor(255,255,255,255));
				//so it's from 10 to 50 high and 130 to 300 tall?
}
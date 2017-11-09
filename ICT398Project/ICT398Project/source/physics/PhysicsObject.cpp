#include "PhysicsObject.h"
#include "equations.h"

using namespace physics;
using namespace types;
using namespace std;

PhysicsObject::PhysicsObject(){
	shape = RECT;
	position = Vector3D();
	linVelocity = Vector3D();
	rotAxis = Vector3D();
	inertia = Matrix3x3();
	rotation = Matrix3x3();
	rotVelocity = 0.0;
	mass = 1.0;
	pointMass = 0.125;

	// Make a cube with side lengths equal to 1
	points.push_back(Vector3D(0.5, 0.5, 0.5));
	points.push_back(Vector3D(-0.5, 0.5, 0.5));
	points.push_back(Vector3D(-0.5, 0.5, -0.5));
	points.push_back(Vector3D(0.5, 0.5, -0.5));
	points.push_back(Vector3D(0.5, -0.5, 0.5));
	points.push_back(Vector3D(-0.5, -0.5, 0.5));
	points.push_back(Vector3D(-0.5, -0.5, -0.5));
	points.push_back(Vector3D(0.5, -0.5, -0.5));

	findSideLengths();
	calcInertia();
}

PhysicsObject::PhysicsObject(int initShape, double initMass, vector<Vector3D> initPoints, Vector3D initPos, Vector3D initLinVel){
	shape = initShape;
	position = initPos;
	linVelocity = initLinVel;
	rotAxis = Vector3D();
	inertia = Matrix3x3();
	rotation = Matrix3x3();
	rotVelocity = 0.0;
	mass = initMass;

	/*
	for(int i = 0; i < initPoints.size(); i++){
		points.push_back(initPoints.at(i));
	}
	*/
	points = initPoints;

	if(points.size() != 0)
		pointMass = mass / points.size();
	else
		pointMass = mass;
	
	findSideLengths();
	calcInertia();
}

double PhysicsObject::getMass(){
	return mass;
}

double PhysicsObject::getPMass(){
	return pointMass;
}

Vector3D PhysicsObject::getPos(){
	return position;
}

Vector3D PhysicsObject::getLinVel(){
	return linVelocity;
}

void PhysicsObject::findSideLengths(){
	double minX = 0.0, maxX = 0.0, minY = 0.0, maxY = 0.0, minZ = 0.0, maxZ = 0.0;

	for(unsigned int i = 0; i < points.size(); i++){
		if(points.at(i).x < minX) minX = points.at(i).x;
		if(points.at(i).x > maxX) maxX = points.at(i).x;
		if(points.at(i).y < minY) minY = points.at(i).y;
		if(points.at(i).y > maxY) maxY = points.at(i).y;
		if(points.at(i).z < minZ) minZ = points.at(i).z;
		if(points.at(i).z > maxZ) maxZ = points.at(i).z;
	}

	if(shape == RECT){
		xLength = maxX - minX;
		yLength = maxY - minY;
		zLength = maxZ - minZ;
	}
	else if(shape == SPHERE){
		xLength = Vector3D((float)(maxX - minX), (float)(maxY - minY), (float)(maxZ - minZ)).length() / 2.0;
	}
}

void PhysicsObject::calcInertia(){
	if(shape == RECT){
		inertia.columns[0].x = (float)MMoIRectangle(mass, yLength, zLength);
		inertia.columns[1].y = (float)MMoIRectangle(mass, xLength, zLength);
		inertia.columns[2].z = (float)MMoIRectangle(mass, xLength, yLength);
	}
	else if(shape == SPHERE){
		inertia.columns[0].x = (float)MMoISphere(mass, xLength);
		inertia.columns[1].y = (float)MMoISphere(mass, xLength);
		inertia.columns[2].z = (float)MMoISphere(mass, xLength);
	}
}

void PhysicsObject::recalcInertia(){
	inertiaAdjust = rotation * inertia;
}

/* Leaving this for now as I'm not sure how Irrlicht stores mesh vertices
void PhysicsObject::calcCoM(){
	for(int i = 0; i < points.size(); i++){
		com += (pointMass * points.at(i));
	}
}
*/
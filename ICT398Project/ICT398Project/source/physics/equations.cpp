#include "equations.h"
#include <math.h>

using namespace types;

double physics::force(double inertia, double accel){
	return (inertia * accel);
}

double physics::momentum(double inertia, double velocity){
	return (inertia * velocity);
}

double physics::inertia(double mass, double radius){
	return (mass * radius * radius);
}

double physics::radialAccel(double radius, double velocity){
	return (radius * velocity * velocity);
}

double physics::kineticEnergy(double inertia, double velocity){
	return ((1/2) * inertia * velocity * velocity);
}

double physics::finalVelocity(double initVel, double accel, double time){
	return (initVel + (accel * time));
}

double physics::finalVelocityWithDistance(double initVel, double accel, double distance){
	return sqrt((initVel * initVel) + (2 * accel * distance));
}

double physics::avgVelocity(double initVel, double finalVel){
	return ((initVel + finalVel) / 2);
}

double physics::distanceTravelled(double initVel, double finalVel, double time){
	return ((1/2) * (initVel + finalVel) * time);
}

double physics::distanceTravelledWithAccel(double initVel, double time, double accel){
	return ((initVel * time) + ((1/2) * accel * time * time));
}

double physics::rotationalToLinear(double rotVal, double radius){
	return (rotVal * radius);
}

double physics::torqueToForce(double torque, double radius){
	return (torque / radius);
}

double physics::linearToRotational(double linVal, double radius){
	return (linVal / radius);
}

double physics::forceToTorque(double force, double radius){
	return (force * radius);
}

double physics::MMoIRectangle(double mass, double xLength, double yLength){
	return (mass * ((xLength * xLength) + (yLength * yLength)) / 12);
}

double physics::MMoISphere(double mass, double radius){
	return ((2/5) * mass * radius * radius);
}

double physics::parallelAxisMMoI(double mmoi, double mass, double axisDist){
	return (mmoi + (mass * axisDist * axisDist));
}

Vector3D physics::linearImpulse(double cor, Vector3D normal, Vector3D initLinVel1, Vector3D initLinVel2, Vector3D initRotVel1, Vector3D initRotVel2, Vector3D radiusVec1,
								Vector3D radiusVec2, double mass1, double mass2, Matrix3x3 inertia1, Matrix3x3 inertia2){
	Vector3D reactionVec = Vector3D();

	
	reactionVec = ((-(1 + cor) * (normal.dotProduct(initLinVel1 - initLinVel2) + initRotVel1.dotProduct(radiusVec1.crossProduct(normal)) - initRotVel2.dotProduct(radiusVec2.crossProduct(normal)))) /
				  ((1 / mass1) + (1 / mass2) + ((radiusVec1.crossProduct(normal).dotProduct(inertia1.inverse() * radiusVec1.crossProduct(normal))) + (radiusVec2.crossProduct(normal).dotProduct(inertia2.inverse() * radiusVec2.crossProduct(normal)))))) * normal;
	

	return reactionVec;
}
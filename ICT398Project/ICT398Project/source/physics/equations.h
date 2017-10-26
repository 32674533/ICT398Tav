/**
	Temp commenting style.
	This file contains definitions for all of the important physics equations.
	Author: Alfred Malone
*/

#include "Types.h"

using namespace types;

namespace physics{
	// Basic equations
	// F = ma or torque = Ia, also works for centripetal force
	double force(double inertia, double accel);
	// P = mv or L = Iw
	double momentum(double inertia, double velocity);
	// I = mr^2
	double inertia(double mass, double radius);
	// a = rw^2
	double radialAccel(double radius, double velocity);
	// KE = 1/2 * mv^2 or KE = 1/2 * Iw^2
	double kineticEnergy(double inertia, double velocity);
	// v = u + at or w(fin) = w(init) + at
	double finalVelocity(double initVel, double accel, double time);
	// v^2 = u^2 + 2as or w(fin)^2 = w(init)^2 + 2a(delta theta)
	double finalVelocityWithDistance(double initVel, double accel, double distance);
	// (u + v)/2 or (w(init) + w(fin))/2
	double avgVelocity(double initVel, double finalVel);
	// s = 1/2 * (u + v) * t or (delta theta) = 1/2 * (w(init) + w(fin)) * t
	double distanceTravelled(double initVel, double finalVel, double time);
	// s = ut + 1/2 * at^2 or (delta theta = w(init) * t + 1/2 * at^2
	double distanceTravelledWithAccel(double initVel, double time, double accel);

	// Conversion equations
	// Rotational to linear
	// v = wr, a(lin) = a(rot) * r, s = (theta) * r
	double rotationalToLinear(double rotVal, double radius);
	// F = t/r
	double torqueToForce(double torque, double radius);

	// Linear to rotational
	// w = v/r, a(rot) = a(lin)/r, (theta) = s/r
	double linearToRotational(double linVal, double radius);
	// t = Fr
	double forceToTorque(double force, double radius);

	//Parallel axis theorem
	// I = I(0) + md^2
	double parallelAxisMMoI(double mmoi, double mass, double axisDist);

	// Frictionless collision response to do with linear impulse - involves tensors
	/**
	* Okay, here's the tricky bit. Need to get the following equation:
	* ((-(1 + e) * (n.dotProduct(initLinVel1 - initLinVel2) + initRotVel1.dotProduct(radiusVec1.crossProduct(n)) - initRotVel2.dotProduct(radiusVec2.crossProduct(n)))) /
	* ((1 / mass1) + (1 / mass2) + ((radiusVec1.crossProduct(n) * (inertia1.inverse() * radiusVec1.crossProduct(n))) + (radiusVec2.crossProduct(n) * (inertia2.inverse() * radiusVec2.crossProduct(n))))) * n
	*
	* where:	e = coefficient of restitution - double
	*			n = unit surface normal vector from point of collision - vector
	*			initLinVel1 = initial linear velocity of first object - vector
	*			initLinVel2 = initial linear velocity of second object - vector
	*			initRotVel1 = initial rotational velocity of first object - vector
	*			initRotVel2 = initial rotational velocity of second object - vector
	*			radiusVec1 = distance from point of contact to centre of mass of first object as a vector
	*			radiusVec2 = distance from point of contact to centre of mass of second object as a vector
	*			mass1 = mass of first object - double
	*			mass2 = mass of second object - double
	*			inertia1 = inertia tensor for first object - 3x3 matrix
	*			inertia2 = inertia tensor for second object - 3x3 matrix
	*/
	Vector3D linearImpulse(double cor, Vector3D normal, Vector3D initLinVel1, Vector3D initLinVel2, Vector3D initRotVel1, Vector3D initRotVel2, Vector3D radiusVec1,
						   Vector3D radiusVec2, double mass1, double mass2, Matrix3x3 inertia1, Matrix3x3 inertia2);
}
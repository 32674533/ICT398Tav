#include <vector>
#include "Types.h"

namespace physics{
#define RECT 1
#define SPHERE 2

	class PhysicsObject{
	public:
		PhysicsObject(int initShape, double initMass, std::vector<types::Vector3D> initPoints, types::Vector3D initPos, types::Vector3D initLinVel);

		// Getters
		double getMass();
		double getPMass();
		types::Vector3D getPos();
		types::Vector3D getLinVel();

		void collisionResponse(PhysicsObject otherObj);
	private:
		types::Vector3D position, com, linVelocity, rotAxis;
		types::Matrix3x3 inertia, inertiaAdjust, rotation;
		std::vector<types::Vector3D> points;
		double rotVelocity, mass, pointMass;

		int shape;
		double xLength, yLength, zLength;

		PhysicsObject();

		// Setters
		void setMass(double newMass);
		void setPMass(double newPMass);
		void setPos(types::Vector3D newPos);
		void setLinVel(types::Vector3D newLinVel);

		void findSideLengths();
		void calcInertia();
		void recalcInertia();
		//void calcCoM();
	};
}
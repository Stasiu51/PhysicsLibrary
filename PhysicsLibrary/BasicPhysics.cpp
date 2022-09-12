#include "BasicPhysics.h"

#ifndef LST
#define LST
#include <list>
#endif

using namespace std;


std::list<PhysicsObject*> BasicPhysics::physicsObjects = *new list<PhysicsObject*>();
std::list<PhysicsConstraint*> BasicPhysics::physicsConstraints = *new list<PhysicsConstraint*>();

void BasicPhysics::update(float deltaTime)
{
	for (list<PhysicsConstraint*>::iterator PC_it = physicsConstraints.begin(); PC_it != physicsConstraints.end(); ++PC_it) {
		(*PC_it)->applyConstraint();
	}

	for (list<PhysicsObject*>::iterator PO_it = physicsObjects.begin(); PO_it != physicsObjects.end(); ++PO_it) {
		(*PO_it)->update(deltaTime);
	}
}

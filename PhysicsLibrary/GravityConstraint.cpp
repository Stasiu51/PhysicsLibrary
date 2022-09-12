#include "GravityConstraint.h"
#include <iostream>

GravityConstraint::GravityConstraint(double gravConst)
{
	_gravConst = gravConst;
	_physicsObjects = *new std::list<PhysicsObject*>();
}

void GravityConstraint::addObject(PhysicsObject* physicsObject)
{
	_physicsObjects.push_back(physicsObject);
}

void GravityConstraint::applyConstraint()
{
	for (std::list<PhysicsObject*>::iterator it1 = _physicsObjects.begin(); it1 != _physicsObjects.end(); it1++) {
		PhysicsObject& po1 = **it1;
		for (std::list<PhysicsObject*>::iterator it2 = _physicsObjects.begin(); it2 != _physicsObjects.end(); it2++) {
			PhysicsObject& po2 = **it2;
			if (it1 == it2) continue;
			Vector3D rel = po2.position - po1.position;
			po1.addForce(_gravConst* (po1._mass * po2._mass / pow(rel.abs(), 2)) * rel.norm());
			std::cout << (po1._mass * po2._mass / pow(rel.abs(), 2)) << std::endl;
		}
	}
}

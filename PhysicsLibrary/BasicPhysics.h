#pragma once

#ifndef FU_H
#define FU_H
#include <functional>
#endif

#ifndef LST
#define LST
#include <list>
#endif

#include "PhysicsObject.h"
#include "PhysicsConstraint.h"

class BasicPhysics
{
private:
	static std::list<PhysicsObject*> physicsObjects;
	static std::list<PhysicsConstraint*> physicsConstraints;
	static void update(float deltaTime);

public:
	static std::function<void(float)>* getUpdateFunction() { return new std::function<void(float)>(update); };
	static void addObject(PhysicsObject * physicsObject) { physicsObjects.push_back( physicsObject); };
	static void addConstraint(PhysicsConstraint * physicsConstraint) { physicsConstraints.push_back( physicsConstraint); };
};


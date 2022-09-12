#include "PhysicsLibrary.h"

void initialiseGraphics(int argc, char** argv)
{
	BasicGraphics::initialise(argc, argv);
}

void startGraphics(std::function<void(float)>* updateFunc)
{
	BasicGraphics::startVisuals(updateFunc);
}

void setGraphicsScale(double scale)
{
	BasicGraphics::setMasterScale(scale);
}

std::function<void(float)>* getPhysicsUpdateFunction()
{
	return BasicPhysics::getUpdateFunction();
}

void addPhysicsObject(PhysicsObject* physicsobject)
{
	return BasicPhysics::addObject(physicsobject);
}

void addPhysicsConstraint(PhysicsConstraint* physicsconstraint)
{
	BasicPhysics::addConstraint(physicsconstraint);
}
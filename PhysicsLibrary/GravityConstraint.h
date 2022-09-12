#pragma once
#include "PhysicsConstraint.h"

#ifndef LST
#define LST
#include <list>
#endif
#include "PhysicsObject.h"


#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif

class PHYSICSLIBRARY_API GravityConstraint :
    public PhysicsConstraint
{
private:
    std::list<PhysicsObject*> _physicsObjects;
    double _gravConst;
public:
    GravityConstraint(double gravConst);
    void addObject(PhysicsObject* physicsObject);
	void applyConstraint() override;
};


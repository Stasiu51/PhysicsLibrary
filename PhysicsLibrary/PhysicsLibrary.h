#pragma once

#if defined PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif

#ifndef FU_H
#define FU_H
#include <functional>
#endif

#include "BasicGraphics.h"
#include "Sphere.h"
#include "Helix.h"
#include "Square.h"
#include "RegularPolygon.h"
#include "BasicPhysics.h"
#include "PhysicsObject.h"
#include "PhysicsConstraint.h"
#include "SpringConstraint.h"
#include "GravityConstraint.h"

extern "C" PHYSICSLIBRARY_API void initialiseGraphics(int argc, char** argv);

extern "C" PHYSICSLIBRARY_API void startGraphics(std::function<void(float)>*updateFunc);

extern "C" PHYSICSLIBRARY_API void setGraphicsScale(double scale);

extern "C" PHYSICSLIBRARY_API std::function<void(float)>*getPhysicsUpdateFunction();

extern "C" PHYSICSLIBRARY_API void addPhysicsObject(PhysicsObject * physicsobject);

extern "C" PHYSICSLIBRARY_API void addPhysicsConstraint(PhysicsConstraint * physicsconstraint);
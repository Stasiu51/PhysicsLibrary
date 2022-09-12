#pragma once
#include "PhysicsConstraint.h"
#include "PhysicsObject.h"
#include "Helix.h"

#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif

class PHYSICSLIBRARY_API SpringConstraint : public PhysicsConstraint
{
private:
	PhysicsObject* _a;
	PhysicsObject* _b;
	Helix* _spring;
	double _k;
	double _natlen;
public:
	SpringConstraint(PhysicsObject& a, PhysicsObject& b, double k, double natlen, Helix& helix);
	void applyConstraint() override;
};


#pragma once
#include "Drawable3D.h"

#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif

class PHYSICSLIBRARY_API PhysicsObject
{
private:
	Drawable3D* _drawable;
	
	
	Vector3D _totalForce;
public:
	double _mass = 0;
	double _damping = 0;
	PhysicsObject(Drawable3D & drawable, double mass,double damping);
	void addForce(Vector3D force);
	void update(double deltaTime);
	Vector3D position;
	Vector3D velocity;

};


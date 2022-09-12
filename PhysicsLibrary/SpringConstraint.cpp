#include "SpringConstraint.h"
#include <iostream>

SpringConstraint::SpringConstraint(PhysicsObject& a, PhysicsObject& b, double k, double natlen, Helix& helix)
{
	_spring = &helix;
	_a = &a;
	_b = &b;
	_k = k;
	_natlen = natlen;
}

void SpringConstraint::applyConstraint()
{
	
	Vector3D relpos = _a->position - _b->position;
	double extension = relpos.abs() - _natlen;

	std::cout << extension << std::endl;
	_b->addForce(_k*extension * relpos.norm());
	_a->addForce(_k*-extension * relpos.norm());
	_spring->position = _a->position;
	_spring->setEnd(_b->position);
}

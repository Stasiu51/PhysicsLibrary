#include "PhysicsObject.h"

PhysicsObject::PhysicsObject(Drawable3D& drawable, double mass,double damping)
{
	_mass = mass;
	_drawable = &drawable;
	_damping = damping;
}

void PhysicsObject::addForce(Vector3D force)
{
	_totalForce += force;
}

void PhysicsObject::update(double deltaTime)
{
	_totalForce += -_damping*velocity.abs() * velocity;
	velocity += deltaTime/_mass  * _totalForce;
	position += deltaTime * velocity;
	_drawable->position = position;
	_totalForce = Vector3D();
}

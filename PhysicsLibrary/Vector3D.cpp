#include "Vector3D.h"
#include <math.h>

Vector3D::Vector3D(double vx, double vy, double vz)
{
	x = vx;
	y = vy;
	z = vz;
}

Vector3D::Vector3D() {
x = 0.0;
y = 0.0;
z = 0.0;
}
double Vector3D::abs()
{
	return sqrt(x * x + y * y + z *z);
}

void Vector3D::operator+=(Vector3D v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}

void Vector3D::operator*=(double scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

Vector3D Vector3D::norm()
{
	double normfactor = 1 / abs();
	return Vector3D(normfactor * x, normfactor * y, normfactor * z);
}

Vector3D operator*(double scalar, Vector3D v)
{
	return Vector3D(scalar * v.x, scalar * v.y, scalar * v.z);
}

Vector3D operator+(Vector3D v1, Vector3D v2)
{
	return Vector3D(v2.x + v1.x, v2.y + v1.y, v1.z + v2.z);
}

Vector3D operator-(Vector3D v1, Vector3D v2)
{
	return Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
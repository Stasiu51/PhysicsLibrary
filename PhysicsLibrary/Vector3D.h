#pragma once

#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif

class PHYSICSLIBRARY_API Vector3D
{
public:
	Vector3D(double vx, double vy, double vz);
	Vector3D();
	double abs();
	Vector3D norm();
	double x;
	double y;
	double z;
	void operator += (Vector3D v);
	void operator *= (double scalar);
};

extern "C" PHYSICSLIBRARY_API Vector3D operator * (double scalar, Vector3D v);
extern "C" PHYSICSLIBRARY_API Vector3D operator + (Vector3D v1, Vector3D v2);
extern "C" PHYSICSLIBRARY_API Vector3D operator - (Vector3D v1, Vector3D v2);



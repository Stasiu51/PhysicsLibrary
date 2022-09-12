#pragma once
#include "Drawable3D.h"

#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif

class  PHYSICSLIBRARY_API Sphere : public Drawable3D
{
private:
	int slices;
	int stacks;
	float rad;
protected:
	std::list<GLfloat*>* getVerts() override { return NULL; };
	std::list<GLfloat*>* getNormals() override { return NULL; };

	void drawCommand() override { 
		glutSolidSphere(rad, slices, stacks); };
	bool isQuads() override { return false; };
	bool isCommand() override { return true; };
public:
	Sphere(int sphereSlices, int sphereStacks, float radius);
};


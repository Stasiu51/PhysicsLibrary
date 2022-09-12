#pragma once
#include "Drawable3D.h"

#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif


class PHYSICSLIBRARY_API  Helix : public Drawable3D
{
private:
	std::list<GLfloat*>* helixverts;
	std::list<GLfloat*>* helixnorms;
	float _length;
protected:
	bool isCommand() override { return false; };
	void drawCommand() override {};
	std::list<GLfloat*>* getVerts() override;
	std::list<GLfloat*>* getNormals() override;
	bool isQuads() override { return true; };

public:
	Helix(float length, float radius, float thickness, int faces, int resolution, int ncoils);
	float length() { return _length; };
	void setEnd(Vector3D pos);
};


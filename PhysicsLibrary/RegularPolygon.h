#pragma once
#include "Drawable3D.h"

#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif

class PHYSICSLIBRARY_API RegularPolygon :public Drawable3D
{
private:
	std::list<GLfloat*>* polyverts;
	std::list<GLfloat*>* polynorms;
protected:
	bool isCommand() override { return false; };
	void drawCommand() override {};
	std::list<GLfloat*>* getVerts() override;
	std::list<GLfloat*>* getNormals() override;
	bool isQuads() override { return false; };
	
public:
	RegularPolygon(int sides);
};
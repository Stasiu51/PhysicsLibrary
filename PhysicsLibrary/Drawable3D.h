#pragma once
#ifndef GL_H
#define GL_H
#include <GL/glut.h>
#endif

#ifndef LST
#define LST
#include <list>
#endif

#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif

#include "Vector3D.h"

class PHYSICSLIBRARY_API Drawable3D
{
private:
	void makeMesh();
protected:
	
	virtual std::list<GLfloat*>* getVerts() = 0;
	virtual std::list<GLfloat*>* getNormals() = 0;
	virtual bool isQuads() = 0;
	virtual bool isCommand() = 0;
	virtual void drawCommand() = 0;
	Drawable3D();
	
public:
	void init();
	int commandIndex = NULL;
	float* scale;
	Vector3D position;
	float* rotations;
	float* colour;
};

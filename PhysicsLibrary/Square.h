#pragma once
#include "Drawable3D.h"

#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif

class PHYSICSLIBRARY_API Square :public Drawable3D
{
private:
	static std::list<GLfloat*>* squareverts;
	static std::list<GLfloat*>* squarenorms;
	
protected:
	bool isCommand() override { return false; };
	void drawCommand() override {};
	bool isQuads() override { return true; };
	std::list<GLfloat*>* getVerts() override;
	std::list<GLfloat*>* getNormals() override;
};


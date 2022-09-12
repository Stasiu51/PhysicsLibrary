#pragma once
#include "Drawable3D.h"
#ifndef LST
#define LST
#include <list>
#endif
#include <iostream>

class Triangle :public Drawable3D
{
private:
	static std::list<GLfloat*>* triverts;
	static std::list<GLfloat*>* trinorms;
	
protected:
	bool isCommand() override { return false; };
	void drawCommand() override {}
	bool isQuads() override { return false; };
	std::list<GLfloat*>* getVerts() override;
	std::list<GLfloat*>* getNormals() override;
};


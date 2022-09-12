#pragma once



#ifndef GL_H
#define GL_H
#include <GL/glut.h>
#endif

#ifndef FU_H
#define FU_H
#include <functional>
#endif


#ifndef LST
#define LST
#include <list>
#endif

#ifndef CT_H
#define CT_H
#include <chrono>
#endif

#include "Drawable3D.h"

class BasicGraphics
{
private:
	static std::chrono::system_clock::time_point lastUpdateTime;
	static std::function<void(float)> updateCallback;
	const static GLfloat light0_ambient[];
	const static GLfloat light0_diffuse[];
	const static GLfloat light1_diffuse[];
	const static GLfloat light1_position[];
	const static GLfloat triverts[][3];
	const static GLfloat timeStep;
	static GLfloat currentTime;
	static std::list<Drawable3D*> drawables;

	static void idle(void);
	static void display(void);
	static double masterScale;

public:
	static void initialise(int argc, char** argv);
	static void startVisuals(std::function<void(float)>* updateFunc);
	static int addDrawable(Drawable3D* drawable);
	static void setMasterScale(double scale) { masterScale = scale; }
};


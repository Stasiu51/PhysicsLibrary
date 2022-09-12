#include "BasicGraphics.h"
#include<iostream>
#include "Vector3D.h"



using namespace std;
bool initialised = false;
const GLfloat BasicGraphics::light0_ambient[] =
{ 0.5, 0.5, 0.5, 1.0 };
const GLfloat BasicGraphics::light0_diffuse[] =
{ 0.0, 0.0, 0.0, 1.0 };
const GLfloat BasicGraphics::light1_diffuse[] =
{ 1.0, 1.0, 1.0, 1.0 };
const GLfloat BasicGraphics::light1_position[] =
{ 3.0, 1.0, 1.0, 0.0 };

double BasicGraphics::masterScale = 1.0;


const GLfloat BasicGraphics::timeStep = 1.0;
GLfloat BasicGraphics::currentTime = 0.0;
list<Drawable3D*> BasicGraphics::drawables;
std::function<void(float)> BasicGraphics::updateCallback;
chrono::system_clock::time_point BasicGraphics::lastUpdateTime;


GLuint commandFillIndex = 0;

void BasicGraphics::initialise(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("red 3D lighted cube");
	commandFillIndex = glGenLists(10);
}

void BasicGraphics::startVisuals(function<void(float)> *updateFunc) {
	updateCallback = *updateFunc;
	cout << "start" << endl;
	glutDisplayFunc(display);
	glutIdleFunc(idle);
		
		
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);

		
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	gluPerspective( /* field of view in degree */ 40.0,
		/* aspect ratio */ 1.0,
		/* Z near */ 1.0, /* Z far */ 10.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.0, 0.0, 5.0,  /* eye is at (0,0,5) */
		0.0, 0.0, 0.0,      /* center is at (0,0,0) */
		0.0, 1.0, 0.);
	glScalef(masterScale, masterScale, masterScale);
	lastUpdateTime = chrono::system_clock::now();
	
	glutSwapBuffers();
	glutMainLoop();
}

int BasicGraphics::addDrawable(Drawable3D* drawable)
{
	drawables.push_back(drawable);
	return (commandFillIndex++);
}

void BasicGraphics::idle(void) {
	chrono::system_clock::time_point currentTime = chrono::system_clock::now();
	chrono::duration<float> diff = currentTime - lastUpdateTime;
	updateCallback(diff.count());
	lastUpdateTime = currentTime;
    glutPostRedisplay();
}
void scaleTransRot(Vector3D pos, float* rots, float *scale, bool inv) {
	
	if (!inv) {
		
		glTranslatef(pos.x, pos.y, pos.z);
		
		glRotatef(rots[2], 0.0, 0.0, 1.0);
		glRotatef(rots[1], 0.0, 1.0, 0.0);
		glRotatef(rots[0], 1.0, 0.0, 0.0);
		glScalef(scale[0],  scale[1], scale[2]);
	}
	else {
		glScalef(1 / scale[0], 1 / scale[1], 1 / scale[2]);
		glRotatef(-rots[0], 1.0, 0.0, 0.0);
		glRotatef(-rots[1], 0.0, 1.0, 0.0);
		glRotatef(-rots[2], 0.0, 0.0, 1.0);
		
		glTranslatef(-pos.x,- pos.y, -pos.z);
		
	}
	

}
void BasicGraphics::display() {
	list<Drawable3D*>::iterator draw_it;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (draw_it = drawables.begin(); draw_it != drawables.end(); ++draw_it) {
		Drawable3D& drawable = **draw_it;
		glEnable(GL_LIGHT1);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, drawable.colour);
		glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

		scaleTransRot(drawable.position, drawable.rotations, drawable.scale, false);
		glCallList(drawable.commandIndex);
		scaleTransRot(drawable.position, drawable.rotations, drawable.scale,  true);
		glDisable(GL_LIGHT1);
	}
	GLenum errCode;
	const GLubyte* errString;
	
	glutSwapBuffers();

	if ((errCode = glGetError()) != GL_NO_ERROR) {
		errString = gluErrorString(errCode);
		fprintf(stderr, "OpenGL Error: %s\n", errString);
	}
}

#include "Drawable3D.h"
#include <list>
#include "BasicGraphics.h"
#include <iostream>
using namespace std;


void Drawable3D::init()
{
	commandIndex = BasicGraphics::addDrawable(this);
	glNewList(commandIndex, GL_COMPILE);
	
	if (isCommand()) drawCommand();
	else makeMesh();

	GLenum errCode;
	const GLubyte* errString;

	if ((errCode = glGetError()) != GL_NO_ERROR) {
		errString = gluErrorString(errCode);
		fprintf(stderr, "OpenGL Error: %s\n", errString);
	}
	glEndList();

}

Drawable3D::Drawable3D()
{
	scale = new float[] {1.0, 1.0, 1.0};
	Vector3D position;
	rotations = new float[] {0.0, 0.0, 0.0};
	colour = new float[] {1.0, 1.0, 1.0, 1.0 };
}

void Drawable3D::makeMesh() {
	if (isQuads()) glBegin(GL_QUADS);
	else glBegin(GL_TRIANGLES);

	
	list<GLfloat*>& normals = *getNormals();
	list<GLfloat*>& verts = *getVerts();
	list<GLfloat*>::iterator vert_it = verts.begin();
	for (list<GLfloat*>::iterator norm_it = normals.begin(); norm_it != normals.end(); ++norm_it) {
		glNormal3fv(*norm_it);
		glVertex3fv(*vert_it);
		++vert_it;
		glVertex3fv(*vert_it);
		++vert_it;
		glVertex3fv(*vert_it);
		++vert_it;
		if (isQuads()) {
			glVertex3fv(*vert_it);
			++vert_it;
		}
		GLenum errCode;
		const GLubyte* errString;

		if ((errCode = glGetError()) != GL_NO_ERROR) {
			errString = gluErrorString(errCode);
			fprintf(stderr, "OpenGL Error: %s\n", errString);
		}
	}
	glEnd();
}
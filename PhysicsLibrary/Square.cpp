#include "Square.h"
using namespace std;
list<GLfloat*>* Square::squareverts = new list<GLfloat*>({
new GLfloat[] { -0.5,-0.5,0.0 },
new GLfloat[] { 0.5,-0.5,0.0 },
new GLfloat[] { 0.5,0.5,0.0 },
new GLfloat[] { -0.5,0.5,0.0 },
	});

list<GLfloat*>* Square::squarenorms = new list<GLfloat*>({
new GLfloat[] { 0.0,0.0,1.0 }
	});


list<GLfloat*>* Square::getVerts() {
	return squareverts;
}

list<GLfloat*>* Square::getNormals()
{
	return squarenorms;
}
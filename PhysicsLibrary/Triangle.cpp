#include "Triangle.h"
using namespace std;
list<GLfloat*>* Triangle::triverts = new list<GLfloat*>({
new GLfloat[] { 0.0,0.0,0.0 },
new GLfloat[] { 0.0,1.0,0.0 },
new GLfloat[] { 1.0,0.0,0.0 }
	});

list<GLfloat*>* Triangle::trinorms = new list<GLfloat*>({
new GLfloat[] { 0.0,0.0,1.0 }
	});


list<GLfloat*>* Triangle::getVerts() {
	return triverts;
}

list<GLfloat*>* Triangle::getNormals()
{
	return trinorms;
}

#include "RegularPolygon.h"
#include <math.h>
#define M_PI acos(-1.0)
using namespace std;
RegularPolygon::RegularPolygon(int sides)
{

	polyverts = new list<GLfloat*>;
	polynorms = new list<GLfloat*>;


	GLfloat *centreV = new GLfloat[]{ 0.0,0.0,0.0 };
	GLfloat *startEnd = new GLfloat[]{ 1.0,0.0,0.0 };
	GLfloat *normal = new GLfloat[]{ 0.0,0.0,1.0 };
	polynorms->push_back(normal);
	polyverts->push_back(startEnd);

	for (int side = 1; side < sides; side++) {
		double angle = 2 * M_PI * side / sides;
		GLfloat* v = new GLfloat[]{ (GLfloat) cos(angle),(GLfloat) sin(angle),0.0 };
		polyverts->push_back(v);
		polyverts->push_back(centreV);
		polynorms->push_back(normal);
		polyverts->push_back(v);	
	}
	polyverts->push_back(startEnd);
	polyverts->push_back(centreV);
}

list<GLfloat*>* RegularPolygon::getVerts() { return polyverts; };
list<GLfloat*>* RegularPolygon::getNormals() { return polynorms; };

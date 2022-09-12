#include "Helix.h"
#include <math.h>
#define M_PI acos(-1.0)
using namespace std;

Helix::Helix(float length, float radius, float thickness, int faces, int resolution, int ncoils)
{
	helixverts = new list<GLfloat*>;
	helixnorms = new list<GLfloat*>;
	_length = length;

	GLfloat*** helixcircles = new GLfloat * *[resolution + 1];
	for (int i = 0; i < resolution + 1; ++i)
		helixcircles[i] = new GLfloat * [faces];

	float stepsize = length / resolution;
	float frequency = 2 * M_PI * ncoils;
	for (int i = 0; i <= resolution; i++)
	{
		float step = stepsize * i;
		float x = radius * cos(frequency * step);
		float y = radius * sin(frequency * step);
		float z = step;
		for (int j = 0; j < faces; j++)
		{
			float theta = j * 2 * M_PI / faces;
			float xnew = thickness * sin(theta) * cos(step * frequency);
			float ynew = thickness * sin(theta) * sin(step * frequency);
			float znew = thickness * cos(theta);

			theta = (j + 0.5) * 2 * M_PI / faces;
			float xnorm = thickness * sin(theta) * cos(step * frequency);
			float ynorm = thickness * sin(theta) * sin(step * frequency);
			float znorm = thickness * cos(theta);
			if (i < resolution)
				helixnorms->push_back(new GLfloat[]{ xnorm,ynorm,znorm });

			helixcircles[i][j] = new GLfloat[]{ x + xnew,y + ynew,z + znew };
		}
	}
	for (int i = 0; i < resolution; i++)
	{
		for (int j = 0; j < faces; j++)
		{
			helixverts->push_back(helixcircles[i][j]);
			helixverts->push_back(helixcircles[i][(j + 1) % faces]);
			helixverts->push_back(helixcircles[i + 1][(j + 1) % faces]);
			helixverts->push_back(helixcircles[i + 1][j]);
		}
	}
	delete helixcircles;
}

void Helix::setEnd(Vector3D pos) {
	float relx = pos.x - position.x;
	float rely = pos.y - position.y;
	float relz = pos.z - position.z;
	scale[2] = sqrt(relx*relx + rely * rely + relz * relz)/_length;
	rotations[2] = -180 * (rely == 0 ? 90 : atan(relx / rely))/ M_PI + (rely > 0 ? 180 : 0);
	rotations[0] = relz == 0 ? 90 : 180 * atan(sqrt(relx*relx + rely*rely)/relz) / M_PI + (relz < 0 ? 180 : 0);
}

list<GLfloat*>* Helix::getVerts() { return helixverts; };
list<GLfloat*>* Helix::getNormals() { return helixnorms; };

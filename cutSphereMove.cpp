/*! \file cutSphereMove.cpp
 * test for the function CreateSkin
 * creates a standard curve wich is a part of a circle (arc)
 * output is writen to a test.asc, and can be read by for example matlab
 */

#include <string>

#include "tpoint3d.h"
#include "harc.h"
#include "createskin.h"

//#############################################################################

int main(int argc, char* argv[])
{

	//Point cloud reference point at 0, 0, 0
    point3d referencePoint( 0., 0., 0. );

	//Number of points in x direction
	const unsigned long nx = 1000;

	//Number of points in y direction
	const unsigned long ny = 500;

	//Number of points in z direction
	const unsigned long nz = 100;

	//Distance between points in the point grid (same fo x, y and z directions)
	const double delta = 1.;

	//Discrete step for move function calculation
	const double deltaT = 0.1;

	//Radius of the sphere
	const double sphereRad = 50.;

	//Name of the file to write the skin data to
	const std::string skinFileName( "test.asc" );

    point3d C(500.,250.,100.);
	//Function object to be evaluated
    HArc func( 0., 0.5, 150., point3d(500.,250.,100.) );

	//Evaluation here
	CreateSkin( referencePoint, nx, ny, nz, sphereRad, func, deltaT, delta, skinFileName );

	return 0;
}

/** @file Rotating2DSquare.cpp
 *	@brief Implementation of a function drawing and rotating a 2D square.
 *
 *  This function draws and animates a 2D square around one of its points, using
 *  a matrix for the rotation transformation.
 *
 *  Besides using the matrix transformations lecture for getting the rotation
 *  matrix to work properly, I also used this source to get the rotation going around
 *  one specified point:
 *  https://academo.org/demos/rotation-about-point/
 */
#include "Rotating2DSquare.h"
/// Line.h is included, as we need it for drawing the sides.
#include "FourSides.h"
/// MCG framework is included, as we need it to make the background white with each iteration.
#include "MCG_GFX_Lib.h"
/// iostream is included to display a message.
#include <iostream>

void RotatingSquare(glm::vec2 _p1, glm::vec2 _p2, glm::vec2 _p3, glm::vec2 _p4)
{
	std::cout << "Press TAB on the GLM window to quit the animation.\n";
	double const pi = 3.14159265; ///< The pi value, which we need for changing degrees to radians.

	/** This is the rotation matrix. On each iteration, it will
	 *  rotate a given vector by 1 degree counter-clockwise. */
	glm::mat2x2 rotation = glm::mat2x2(cos(-1 * pi / 180), sin(-1 * pi / 180), -sin(-1 * pi / 180), cos(-1 * pi / 180));

	while (MCG::ProcessFrame()) ///< This while loop will rotate the square until the users decides to exit.
	{
		MCG::SetBackground(glm::ivec3(255, 255, 255)); /**< Sets the background to be white with each rotation, as we do not want
													    *   the animation to leave traces. */

		/** The calculations below:
		 *  - Substract _p1 from each given point to change the origin of rotation to _p1.
		 *  - Apply the rotation to the given point.
		 *  - Move the point back.
		 *
		 *  _p1 is not modified as its x and y values do not need to change. */
		_p2 = _p2 - _p1;
		_p2 = rotation * _p2;
		_p2 = _p2 + _p1;
		_p3 = _p3 - _p1;
		_p3 = rotation * _p3;
		_p3 = _p3 + _p1;
		_p4 = _p4 - _p1;
		_p4 = rotation * _p4;
		_p4 = _p4 + _p1;

		FourSides(_p1, _p2, _p3, _p4); ///< This line draws the square using the rotated points.
	}
	/// When the program quits, set the background to white.
	MCG::SetBackground(glm::vec3(255, 255, 255));
}
/** @file Bezier.cpp
 *	@brief Implementation of a function drawing Bezier curves.
 *
 *  The function in this file draws a Bezier curve, having two 2D vectors as the start and end location of the line,
 *  with a third 2D vector as the control point, on which the curvature is based. 
 *
 *  I took the equation for the Bezier curves from our maths lecture on parametric equations. 
 *  Thanks, Leigh!
 */

#include "Bezier.h"
/// MCG framework is included due to the use of the DrawPixel function.
#include "MCG_GFX_Lib.h"

void Bezier(glm::vec2 _a, glm::vec2 _b, glm::vec2 _c)
{
	glm::vec2 temp; ///< This is the 2D vector that will be used for drawing the curved line.
	glm::vec3 blue = glm::vec3(0, 0, 255); ///< Just a 3D vector used for a colour, so the code is easier to read.

	for (float i = 0.0f; i <= 1; i += 0.0001) /**< The float "i" used in this for loop is actually the value "t" used
											   *  in the equation for Bezier curves. That is why the intervals have been set to 0.0001,
											   *  to ensure that the curved line seems without any breaks. In theory, if one would zoom
											   *  deeply into the line, the breaks could be seen. */
	{
		temp.x = ((1 - i)*(1 - i))*_a.x + _c.x * 2 * i*(1 - i) + (i*i)*_b.x; ///< Calculating temp.x from the equation (1-t^2)*Ax + Cx*2*t*(1-t)*(t)^2*Bx.
		temp.y = ((1 - i)*(1 - i))*_a.y + _c.y * 2 * i*(1 - i) + (i*i)*_b.y;  ///< Calculating temp.y from the equation (1-t^2)*Ay + Cy*2*t*(1-t)*(t)^2*By.

		MCG::DrawPixel(temp, blue); ///< This line draws the calculated point.
	}
}
/** @file Triangle.cpp
*	@brief Implementation of functions drawing a triangle, filled or not.
*/

#include "Triangle.h"
/// Line.h is included as we need it for drawing the sides of a triangle.
#include "Line.h"

/** Similarly to FourSides.cpp and Hexagon.cpp, this function simply calls Line() three times
 *  to draw the sides of a triangle, and could be implemented straight where it is needed.
 *  I decided to separate it into its own file not only for code modularity, as it is 
 *  also often used by the Sierpinski() function. */
void Triangle(glm::vec2 const _p1, glm::vec2 const _p2, glm::vec2 const _p3)
{
	Line(_p1, _p2);
	Line(_p2, _p3);
	Line(_p3, _p1);
}

/** This function uses a neat trick, as it fills the triangle using the formula
 *  for a weighted average between two points. That means moving on one side (e.g. BC) of
 *  the triangle by the use of the t value and drawing pixels in the meantime,
 *  giving us a line inside of the shape (similar approach to my implementation of the Bezier curves).
 *  Put that through a loop to go through each point on one side, and voila, we receive a filled triangle.
 *
 *  A future TODO could be using Barycentric coordinates to give a nice Gouraud triangle.
 *
 *  I took the formula from:
 *  https://www.khanacademy.org/partner-content/pixar/environment-modeling-2/mathematics-of-parabolas2-ver2/v/weighted-average-two-points */
void FilledTriangle(glm::vec2 const _p1, glm::vec2 const _p2, glm::vec2 const _p3)
{
	Triangle(_p1, _p2, _p3); ///< This line draws the sides of the triangle.

	float t; ///< The t value, used later on in the formula.
	glm::vec2 temp; ///< A 2D vector, storing the current point on the side of _p1 and _p3.

	for (t = 0.0f; t < 1; t += 0.001f) ///< For loop, going through each point on the side of _p1 and _p3.
	{
		temp.x = (1 - t)*_p1.x + t*_p3.x; ///< Calculating the X value from the equation (1 - t)*A + t*B.
		temp.y = (1 - t)*_p1.y + t*_p3.y; ///< Calculating the Y value from the equation (1 - t)*A + t*B.
		Line(_p2, temp); ///< This line draws the line from _p2 to the point on the side of _p1 and _p3.
	}
}
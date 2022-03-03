/** @file Sierpinski.cpp
 *	@brief Implementation of a recursive function drawing the Sierpinski triangle.
 *
 *  I had some trouble with the recursion going on one side initially.
 *  These sources helped me to set the equations right:
 * 	https://www2.cs.duke.edu/courses/fall01/cps001/labs/lab7.html
 *  https://www2.cs.duke.edu/courses/cps001/summer05/labs/lab7.html
 *  https://stackoverflow.com/a/33166953
 */

#include "Sierpinski.h"
/// Triangle.h is included as we need it to draw triangles.
#include "Triangle.h"

void Sierpinski(glm::vec2 _x, glm::vec2 _y, glm::vec2 _z, int generation)
{
	/// This if statement checks if the current generation is the last one.
	if (generation == 1)
	{
		Triangle(_x, _y, _z); /**< If the if statement is true, then it just draws a triangle 
							   *   using the passed 2D points, as the recursion ends with this generation level. */
	}

	else /**< Else, if the current generation is not the last one,
		  *   calculate the midpoints and recursively call the function. */
	{
		/// The lines below initialize the midpoints of XY, YZ and XZ sides.
		glm::vec2 p1 = Midpoint(_x, _y);
		glm::vec2 p2 = Midpoint(_y, _z);
		glm::vec2 p3 = Midpoint(_z, _x);

		/** The lines below call the Sierpinski() function, using recursion to draw the fractal set
		 *  in each part of the triangle - left, upper and right. 
		 * 
		 *  It uses the midpoint of each side to do that.
		 *
		 *  The generation parameter is passed as well, being decremented as 
		 *  each recursion brings us closer to the end. */
		Sierpinski(_x, p1, p3, generation - 1); ///< The parameters in here except of the generation are: the _x corner (A), and the midpoints of XY and XZ.
		Sierpinski(p1, _y, p2, generation - 1); ///< The parameters in here except of the generation are: the _y corner (B), and the midpoints of XY and YZ.
		Sierpinski(p3, p2, _z, generation - 1); ///< The parameters in here except of the generation are: the _z corner (C), and the midpoints of XZ and YZ.
	}
}

/// This function calculates the midpoint of two 2D points.
glm::vec2 Midpoint(glm::vec2 _p1, glm::vec2 _p2)
{
	return glm::vec2((_p1.x + _p2.x) / 2, (_p1.y + _p2.y) / 2);
}
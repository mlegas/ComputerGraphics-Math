/** @file Cantor.cpp
 *	@brief Implementation of a recursive function drawing the Cantor set.
 *
 *  The function implemented in this file draws a Cantor set, having a 2D vector passed as a parameter 
 *  as the first point in the set, as well as the initial line length. It uses recursion to draw the later
 *  lines, the whole program being controlled by an if statement.
 *
 *  For this function, I used this source as the explanation of how to draw the Cantor set:
 *  https://infinityplusonemath.wordpress.com/2017/10/21/the-cantor-set/
 */
#include "Cantor.h"
/// Line.h is included, as we need it for drawing the lines in the Cantor set.
#include "Line.h"

void Cantor(glm::vec2 _p1, float _length)
{
	/** This if statement checks if the given length is not below 1, as otherwise
	 *  we would have trouble drawing lines due to them having a length below 1. 
	 *  Therefore it also controls how long should the recursion go on. */
	if (_length >= 1)
	{
		glm::vec2 temp; ///< This 2D vector will be used to draw a line between it and p1.
		temp.x = _p1.x + _length; ///< This takes the p1's x location and adds length to it, so a line can be drawn.
		temp.y = _p1.y; ///< Making sure that the points are on the same Y height.

		Line(_p1, temp); ///< Draws a line between those two points.

		_p1.y += 40; ///< Distances the next instantiation of the Cantor set away from the current one, so it can be seen more clearly.
		Cantor(_p1, _length / 3); ///< Calls the Cantor function using the p1, with the length of the line divided by 3.

		_p1.x += _length * 2 / 3; ///< Moves the p1.x to the right by two-thirds of the length value.
		Cantor(_p1, _length / 3); ///< Calls the Cantor function using the modified p1, again with the line's length divided by 3.
	}
}
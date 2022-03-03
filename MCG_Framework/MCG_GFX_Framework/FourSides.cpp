/** @file FourSides.cpp
 *	@brief Implementation of functions drawing a four-sided shape, filled or not.
 */

#include "FourSides.h"
/// Line.h is included, as we need it for drawing the sides.
#include "Line.h"

/** The FourSides function basically calls Line() four times to draw a "wire-frame" four-sided shape.
 *  Those calls could be implemented straight away into the code, but for more code modularity and
 *  cleanness I created a separate function for it.
 *
 *  As the amount of the possible basic shapes grew, this function changed names quite a bit.
 *  Initially set as Square(), it changed to Rectangle(), to be finally set as FourSides(). */
void FourSides(glm::vec2 const _p1, glm::vec2 const _p2, glm::vec2 const _p3, glm::vec2 const _p4)
{
	Line(_p1, _p2);
	Line(_p2, _p3);
	Line(_p3, _p4);
	Line(_p4, _p1);
}

/** The FilledRectangle function fills a rectangle by drawing lines between two sides of the shape.
 *	The function does so by setting the pixel position's x value to _p1.x, incrementing the y value
 *  and drawing lines between two sides until the pixel position goes out of boundaries.
 *
 *  Previously, the function went through each pixel on the screen, having the if statement also check if
 *  the distance between x and _p2.x was the same as the distance between _p1.x and _p2.x.
 *
 *  I removed this check and set the x value to _p1.x to optimise the code, as the only benefit
 *  of the previous version of the code was that the function would still work if the sides were flipped,
 *  which is not needed. */
void FilledRectangle(glm::vec2 const _p1, glm::vec2 const _p2, glm::vec2 const _p3, glm::vec2 const _p4)
{
	for (int y = 0; y < 480; y++) ///< For loop, going through the entire screen height.
	{			
		if (y >= _p2.y && y <= _p4.y) ///< If statement, checking if the Y value of the pixel position is in the shape.
		{
			Line(glm::vec2(_p1.x, y), glm::vec2(_p2.x, y)); /**< Draws a line between _p1.x and _p2.x. The Y value is used
															 *   to move the points on the AD and BC sides. Initially, it will draw
															 *   a line between _p1 and _p2, and then on each iteration it will
															 *   create another line one pixel lower. */
		}
	}
}


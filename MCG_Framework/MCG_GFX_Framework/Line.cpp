/** @file Line.cpp
 *	@brief Implementation of Bresenham's line algorithm.
 *
 *  This function is the base function for most of the shape drawing functions.
 *  It makes use of the Bresenham's line algorithm, as I find it to have no trouble
 *  drawing lines that are vertical or horizontal.
 *
 *	It also uses linear interpolation for the colour, for which
 *  I took the equation from one of the MCG lectures.
 *
 *  The pseudocode for Bresenham's line algorithm has been taken from:
 *  https://www.youtube.com/watch?v=zytBpLlSHms&t=272s
 */
#include "Line.h"
/// MCG framework is included due to the use of the DrawPixel() function.
#include "MCG_GFX_Lib.h"

void Line(glm::vec2 const _p1, glm::vec2 const _p2)
{
	glm::vec2 p1; ///< Creates a new 2D vector, which will take the value of _p1.
	glm::vec2 p2; ///< Creates a new 2D vector, which will take the value of _p2.

	/** These assignments cast the float value of _p1 and _p2 to integers. 
	 *  The reason for this is to make sure the Line() function runs smoothly in
	 *  fractal sets such as Cantor or Sierpinski, as well as during the use of rotations,
	 *  where the possibility of X and Y values such as e.g. 4.349 is high. */
	p1.x = (int)_p1.x; 
	p1.y = (int)_p1.y;
	p2.x = (int)_p2.x;
	p2.y = (int)_p2.y;

	/** These declarations create the initial RGB values, which will be later used
	 *  in setting the colour of a drawn pixel. */
	float r = 0;
	float g = 0;
	float b = 0;

	/** Check if the points are the same, if so - just draw a pixel.
	 *  Black colour is used, as almost all of the used background are white. */
	if (p1.x == p2.x && p1.y == p2.y)
	{
		MCG::DrawPixel(glm::vec2(p1.x,p1.y), glm::vec3(r,g,b));
	}
	else
	{
		float slope; ///< The slope of the line.
		float pitch; ///< Pitch, the offset from the slope of the line.
		float slopex, slopey; ///< Slopes of Y and X values.
		float deltay = p2.y - p1.y; ///< The rate of change of the Y value.
		
		/** Check if the rate of change of the Y value is below zero.
		 *  If it is, set the slope of Y to -1 (to be negative). */
		if (deltay < 0)
		{
			slopey = -1;
		}
		/** If the rate of change of the Y value is not below zero,
		 *  set the slope of Y to 1 (to be positive). */
		else
		{
			slopey = 1;
		}
		
		float deltax = p2.x - p1.x; ///< The rate of change of the X value.
				
		/** Check if the rate of change of the X value is below zero.
		 *  If it is, set the slope of X to -1 (to be negative). */
		if (deltax < 0)
		{
			slopex = -1;
		}
		/** If the rate of change of the X value is not below zero,
		 *  set the slope of X to 1 (to be positive). */
		else
		{
			slopex = 1;
		}

		/** This if statement checks if the rate of change of the value of X
		 *  is higher than the rate of change of the value of Y. 
		 *  If it is, it will base the drawing of the line more on the X axis, as
		 *  well as any further calculations. */
		if (abs(deltay) < abs(deltax))
		{
			slope = deltay / deltax; /**< Sets the slope of the line to the rate of change in Y axis divided
									  *   by the rate of change in the X axis. */

			pitch = p1.y - slope * p1.x; /**< Sets the pitch (offset), with the slope of the line
										  *   multiplied by the X value of p1 and subtracted from the Y value of p1. */

			/** The declarations below set the rate of change in colours,
			 *  which will be later on added to RGB values to interpolate 
			 *  the colour while drawing a line. */
			float deltar = (0 - 255) / (_p2.x - _p1.x);
			float deltag = (255 - 0) / (_p2.x - _p1.x);
			float deltab = (255 - 0) / (_p2.x - _p1.x);

			while (p1.x != p2.x) /**< This while condition ensures that the pixels will be drawn
								  *   until the X value of p1 equals the X value of p2.
								  *
								  *   Why X and not Y? It is because the rate of change in X's value
								  *   is higher than the rate of change in Y's value. */
			{
				/// The assignments below interpolate the colour on the line.
				r += deltar;
				g += deltag;
				b += deltab;

				MCG::DrawPixel(glm::vec2(p1.x, (int)(slope*p1.x + pitch)), glm::vec3(r,g,b)); /**< This line draws the pixels creating the line we want,
																							   *   setting the Y value to the general slope of the line
																							   *   multiplied by the X value of p1, with the pitch added at the end. */
				p1.x += slopex; ///< Adds the slope of the X value to p1's X value.
			}
		}

		/** Else, if the rate of change of the value of Y is higher
		 *  than the rate of change of the value of X, the line drawing
		 *  algorithm will base the drawing of the line more on the Y axis, as
		 *  well as any further calculations. */
		else
		{
			slope = deltax / deltay; /**< Sets the slope of the line to the rate of change in X axis divided
									  *   by the rate of change in the Y axis. */

			pitch = p1.x - slope * p1.y; /**< Sets the pitch (offset), with the slope of the line
										  *   multiplied by the Y value of p1 and subtracted from the X value of p1. */

			/** The declarations below set the rate of change in colours,
			 *  which will be later on added to RGB values to interpolate
			 *  the colour while drawing a line. */
			float deltar = (0 - 255) / (_p2.y - _p1.y);
			float deltag = (255 - 0) / (_p2.y - _p1.y);
			float deltab = (255 - 0) / (_p2.y - _p1.y);

			while (p1.y != p2.y) /**< This while condition ensures that the pixels will be drawn
								  *   until the Y value of p1 equals the Y value of p2.
								  *
								  *   Why Y and not X? It is because the rate of change in Y's value
								  *   is higher than the rate of change in X's value.*/
			{
				/// The assignments below interpolate the colour on the line.
				r += deltar;
				g += deltag;
				b += deltab;

				MCG::DrawPixel(glm::vec2((int)(slope*p1.y + pitch), p1.y), glm::vec3(r, g, b)); /**< This line draws the pixels creating the line we want,
																								 *   setting the X value to the general slope of the line
																								 *   multiplied by the Y value of p1, with the pitch added at the end. */
				p1.y += slopey; ///< Adds the slope of the Y value to p1's Y value.
			}
		}
	}
	/** This line draws the final pixel, as the loop condition for drawing the line
	 *  does not allow p1's values to be equal to p2's. The only possible and very, very minor
	 *  drawback is that in cases where p1 equals p2 at the start of the function, it will draw the pixel twice. */
	MCG::DrawPixel(glm::vec2(p2.x, p2.y), glm::vec3(r, g, b));
}
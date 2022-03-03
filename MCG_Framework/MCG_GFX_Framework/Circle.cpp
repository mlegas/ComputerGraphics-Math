/** @file Circle.cpp
 *	@brief Implementation of functions drawing a circle, filled or not.
 *
 *  The implementation uses the distance formula to draw the circle, as it simply checks
 *  if the distance between the pixel location and the centre of the circle is the same as
 *  the radius. I believe using the equation of a circle would work just fine as well.
 *
 *  I took the equation for the distance formula from:
 *  http://www.mathwarehouse.com/algebra/distance_formula/index.php
 */

#include "Circle.h"
/// MCG framework is included due to the use of the DrawPixel() function.
#include "MCG_GFX_Lib.h"
/// cmath is included due to the use of pow() and sqrt() functions.
#include <cmath>

void Circle(glm::vec2 const _centre, int const _radius)
{
	for (int y = 0; y < 480; y++) ///< For loop, going through the entire screen height.
	{
		for (int x = 0; x < 640; x++) ///< For loop, going through the entire screen width.
		{
			if (int(sqrt((pow((x - _centre.x),2)) + (pow((y - _centre.y),2)))) == _radius) /**< This if statement checks if the distance between the pixel location
																						    *   and the centre of the circle is the same as the radius. If it is,
																							*   it will draw the pixel, creating a "wire-frame" of the circle
																							*   when the function ends. */
			{
				MCG::DrawPixel(glm::vec2(x, y), glm::vec3(255, 0, 0)); ///< If the condition was met, this draws the pixel.
			}
		}
	}
}

void FilledCircle(glm::vec2 const _centre, int const _radius)
{

	for (int y = 0; y < 480; y++) ///< For loop, going through the entire screen height.
	{
		for (int x = 0; x < 640; x++) ///< For loop, going through the entire screen width.
		{
			if (int(sqrt((pow((x - _centre.x), 2)) + (pow((y - _centre.y), 2)))) <= _radius) /**< This if statement checks if the distance between the pixel location
																							  *   and the centre of the circle is the same as or less than the radius.
																							  *   If it is, it will draw the pixel, creating a filled circle,
																							  *   when the function ends.*/
			{
				MCG::DrawPixel(glm::vec2(x, y), glm::vec3(255, 0, 0)); ///< If the condition was met, this draws the pixel.
			}
		}
	}
}
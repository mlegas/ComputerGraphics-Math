/** @file Mandelbrot.cpp
 *	@brief Implementation of a function drawing the Mandelbrot set.
 *
 *  This function draws the Mandelbrot set. It uses complex
 *  numbers for the C and Z values in the equation.
 *
 *  To understand the calculations behind the Mandelbrot set, 
 *  like for example the expanded equation, I used a lot from these sources:
 *  https://hardmath123.github.io/scratch-mandelbrot.html
 *  http://beej.us/blog/data/mandelbrot-set/
 */

/// MCG framework is included due to the use of the DrawPixel function.
#include "MCG_GFX_Lib.h"
/// cmath is included due to the use of the pow() function.
#include <cmath>
/// complex is included as the function uses complex numbers.
#include <complex>

void Mandelbrot()
{
	/// These are the declarations of complex numbers C and Z.
	std::complex<float> C, Z;

	float temp; ///< This float is later used for storing the new real value of the complex number Z.
	float zoom = 150; ///< This float is used as a scale (150x). Change it for a bigger or lower zoom.
	int iterations; ///< This int is later used for storing the amount of current iterations.

	for (int y = 0; y < 480; y++) ///< For loop, going through the entire screen height.
	{
		for (int x = 0; x < 640; x++) ///< For loop, going through the entire screen width.
		{
			/** These two assignments, besides setting the complex number C with each loop iteration, 
			 *	set the origin of the Mandelbrot set to the center of the screen, 
			 *  divided by the zoom scale. 
			 *  Change the values to change the origin. */
			C.real((x-320)/zoom);
			C.imag((y-240)/zoom);
			/** These two assignments set the Z values to zero with each loop iteration, as
			 *  that is from where the iterations of the Z^2 + C equation start. */
			Z.real(0);
			Z.imag(0);

			/** This for loop checks if the number Z escapes to infinity with the
			 *  given C number, either checking if the amount of iterations is equal to/over the maximum, 
			 *  or if the real or imaginary part of the Z complex number is above 2 
			 *  (because that means that the number is not part of the set). 
			 *
			 *	The max number of iterations could be lowered to
			 *  50-100 with only a very marginal loss of accuracy. */
			for (iterations = 0; iterations < 5000 && (pow(std::real(Z), 2) + pow(std::imag(Z), 2)) <= 4; iterations++)
			{
				///The equations below are taken from expanding the equation for the Mandelbrot set (check first source).
				temp = (pow(std::real(Z), 2) - pow(std::imag(Z), 2)) + std::real(C); ///< Getting the new real part of the Z complex number.
				Z.imag(2 * (std::real(Z) * std::imag(Z)) + std::imag(C)); ///< Getting and setting the new imaginary part of the Z complex number.
				Z.real(temp); ///< Setting the calculated real part of the Z complex number.
			}

			if (iterations < 5000) /**< If the iterations are below the maximum, that means that the number is
								   *   not part of the Mandelbrot set. */
			{
				/** The line below draws a pixel, with a shade colour depending on how long did it take to establish
				 *  that the current iteration is not part of the Mandelbrot set. */
				MCG::DrawPixel(glm::vec2(x, y), glm::vec3(iterations << 4, iterations << 8, iterations << 16)); /**< The bit shifts are used to create a shade,
																												 *   with a red spectre. */
			}
			else /**< If iterations are over the maximum, this means that the number is part of the Mandlebrot set,
				  * and should be drawn with a black colour. */
			{
				MCG::DrawPixel(glm::vec2(x, y), glm::vec3(0, 0, 0)); ///< Draws a pixel with a black colour.
			}
		}
	}
}
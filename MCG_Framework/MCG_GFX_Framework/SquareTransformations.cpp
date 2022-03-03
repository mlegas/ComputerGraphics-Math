/** @file SquareTransformations.cpp
 *	@brief Implementation of a function demonstrating matrix transformations.
 *
 *  All of the matrix transformations have been taken from the maths lecture about them.
 */

#include "SquareTransformations.h"
/// FourSides.h is included, as we need it for drawing a square.
#include "FourSides.h"
/// MCG framework is included due to a large use of its functions.
#include "MCG_GFX_Lib.h"
/// iostream is included to display messages.
#include <iostream>

void SquareTransformations(glm::vec2 const _p1, glm::vec2 const _p2, glm::vec2 const _p3, glm::vec2 const _p4)
{
	double const pi = 3.14159265; ///< The pi value, which will be used for converting from degrees to radians.

	/// 3D vectors used for colours.
	glm::vec3 black = glm::vec3(0, 0, 0);
	glm::vec3 white = glm::vec3(255, 255, 255);

	MCG::SetBackground(black); /**< Sets the MCG's framework window background to be black,
							    *   as it is easier to see white points on a black background than
								*   black ones on white background. */

	/// The lines below draw 4 while pixels on the screen.
	MCG::DrawPixel(_p1, white);
	MCG::DrawPixel(_p2, white);
	MCG::DrawPixel(_p3, white);
	MCG::DrawPixel(_p4, white);

	std::cout << "The background has been changed to black to see the points more clearly.\n\n";
	std::cout << "We're starting with four points, drawn on the screen.\n";
	std::cout << "Press TAB on the GLM window to translate the points.\n";

	/** The lines below show the drawn pixels, and then after getting input from the user,
	 *  the function wipes the screen black, as well as cleaning the terminal. */
	MCG::ShowAndHold();
	MCG::SetBackground(black);
	system("CLS");

	/// The lines below translate each of the points.
	glm::vec2 p1 = _p1 + glm::vec2(-300, -100);
	glm::vec2 p2 = _p2 + glm::vec2(350, -250);
	glm::vec2 p3 = _p3 + glm::vec2(300, 100);
	glm::vec2 p4 = _p4 + glm::vec2(50, 50);

	/// The lines below draw 4 while pixels on the screen.
	MCG::DrawPixel(p1, white);
	MCG::DrawPixel(p2, white);
	MCG::DrawPixel(p3, white);
	MCG::DrawPixel(p4, white);

	std::cout << "The points have been successfully translated.\n";
	std::cout << "Press TAB on the GLM window to rotate the points (10 degrees).\n";

	/** The lines below show the drawn pixels, and then after getting input from the user,
	 *  the function wipes the screen black, as well as cleaning the terminal. */
	MCG::ShowAndHold();
	MCG::SetBackground(black);
	system("CLS");

	glm::mat2x2 rotation = glm::mat2x2(cos(-10 * pi / 180), sin(-10 * pi / 180), -sin(-10 * pi / 180), cos(-10 * pi / 180)); ///< This line sets the rotation matrix.

	/// The lines below multiply each point by the rotation matrix.
	p1 = rotation * p1;
	p2 = rotation * p2;
	p3 = rotation * p3;
	p4 = rotation * p4;

	/// The lines below draw 4 while pixels on the screen.
	MCG::DrawPixel(p1, white);
	MCG::DrawPixel(p2, white);
	MCG::DrawPixel(p3, white);
	MCG::DrawPixel(p4, white);

	std::cout << "The points have been successfully rotated.\n";
	std::cout << "Press TAB on the GLM window to draw lines.\n";

	/** The lines below show the drawn pixels, and then after getting input from the user,
	 *  the function wipes the screen black, as well as cleaning the terminal. */
	MCG::ShowAndHold();
	MCG::SetBackground(black);
	system("CLS");

	FourSides(p1, p2, p3, p4); ///< This line draws the square using the transformated points.

	std::cout << "The lines have been drawn.\n";
	std::cout << "Press TAB on the GLM window to scale the points and draw the lines again.\n";

	/** The lines below show the drawn pixels, and then after getting input from the user,
	 *  the function wipes the screen black, as well as cleaning the terminal. */
	MCG::ShowAndHold();
	MCG::SetBackground(black);
	system("CLS");

	glm::mat2x2 scale = glm::mat2x2(0.25, 0, 0, 0.25); ///< This line sets the scale matrix.

	/// The lines below multiply each point by the scale matrix, scaling each point by 0.25x.
	p1 = scale * p1;
	p2 = scale * p2;
	p3 = scale * p3;
	p4 = scale * p4;

	FourSides(p1, p2, p3, p4); ///< This line draws the square using the transformated points.

	std::cout << "Done!\n";
	std::cout << "Press TAB on the GLM window to quit.\n";

	/** The lines below show the drawn pixels, and then after getting 
	 *  input from the user, the function wipes the screen white. */
	MCG::ShowAndHold();
	MCG::SetBackground(white);

}
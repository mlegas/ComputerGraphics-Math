/** @file Menu.cpp
 *	@brief Implementation of all menus in the program.
 *
 *  This is the behemoth. This is the implementation of menus
 *  in the program, which allow to run every function that has been
 *  implemented in the code.
 *
 *  Most of the code in here is self-explanatory and part of it repeats
 *  anyway, therefore I will try to limit the amount of comments in here 
 *  to the most necessary ones.
 *
 *  Check the beginning of the BasicShapesMenu() for a thorough explanation of  
 *  the menu mechanism, as all of the menus are very similar to each other.
 */

/** All of the local header files are included, as they all can be possibly
 *  called from the functions implemented in this file. 
 *
 *  The GLM includes are used for the use of parameters when calling functions.
 *  MCG framework is included for the use of its functions in the QuitDraw() function.
 *  iostream is included for handling text output and user input. */
#include "Menu.h"
#include "Bezier.h"
#include "Cantor.h"
#include "Circle.h"
#include "FourSides.h"
#include "GLM/vec2.hpp"
#include "GLM/vec3.hpp"
#include "Hexagon.h"
#include "Line.h"
#include "Mandelbrot.h"
#include "MCG_GFX_Lib.h"
#include "Rotating3DPyramid.h"
#include "Rotating2DSquare.h"
#include "Sierpinski.h"
#include "SquareTransformations.h"
#include "Triangle.h"
#include <iostream>

/// These defines are used to limit repeating code.
#define Drawing std::cout << "Drawing in progress...\n";
#define Drawn std::cout << "Drawn!\n\n";
#define Clear system("CLS"); ///< Clears the terminal from text.

/// This menu is for drawing basic 2D "wire-frame" shapes.
void BasicShapesMenu()
{
	bool quitMenu = false; ///< A boolean to check if the user has decided to quit the menu.
	int choice; ///< An integer used later for choosing in the menu.

	while (!quitMenu) ///< Shows the menu until the user quits it.
	{
		bool correctChoice = false; ///< A boolean to check if the user made a correct choice.
		while (!correctChoice) ///< Asks for user input until a correct choice has been made.
		{
			std::cout << "Choose what would you like to view:\n";
			std::cout << "1. Line\n";
			std::cout << "2. Square\n";
			std::cout << "3. Rhombus\n";
			std::cout << "4. Rectangle\n";
			std::cout << "5. Hexagon\n";
			std::cout << "6. Trapezoid\n";
			std::cout << "7. Triangle\n";
			std::cout << "8. Circle\n";
			std::cout << "0. Quit menu\n\n";

			std::cin >> choice; ///< Gets user input to an integer.
			switch (choice)
			{
				case 1:
				{
					correctChoice = true; ///< The user made a correct choice, so change the value of the boolean.	
					/** These two defines are two std::cout's. I just made them 
					 *  as defines since they repeat a lot. */
					Clear;
					Drawing;
					Line(glm::vec2(50, 100), glm::vec2(600, 400)); ///< Draws a line between (50,100) and (600,400).
					QuitDraw(); /**< After drawing calls, shows the drawing on the MCG framework window.
								 *   Check the function for more info. */
					break;
				}
				case 2:
				{
					correctChoice = true;
					Clear;
					Drawing;
					/// This line draws a square with the parameters set for A, B, C and D.
					FourSides(glm::vec2(200, 200), glm::vec2(400, 200), glm::vec2(400, 400), glm::vec2(200, 400));
					QuitDraw();
					break;
				}
				case 3:
				{
					correctChoice = true;
					Clear;
					Drawing;
					/// This line draws a rhombus with the parameters set for A, B, C, and D.
					FourSides(glm::vec2(100, 200), glm::vec2(300, 400), glm::vec2(500, 200), glm::vec2(300, 0));
					QuitDraw();
					break;
				}
				case 4:
				{
					correctChoice = true;
					Clear;
					Drawing;
					/// This line draws a rectangle with the parameters set for A, B, C, and D.
					FourSides(glm::vec2(200, 200), glm::vec2(600, 200), glm::vec2(600, 400), glm::vec2(200, 400));
					QuitDraw();
					break;
				}
				case 5:
				{
					correctChoice = true;
					Clear;
					Drawing;
					/// This line draws a hexagon with the parameters set for A, B, C, D, E and F.
					Hexagon(glm::vec2(100, 200), glm::vec2(200, 100), glm::vec2(300, 100), glm::vec2(400, 200), glm::vec2(300, 300), glm::vec2(200, 300));
					QuitDraw();
					break;
				}
				case 6:
				{
					correctChoice = true;
					Clear;
					Drawing;
					/// This line draws a trapezoid with the parameters set for A, B, C, and D.
					FourSides(glm::vec2(100, 300), glm::vec2(200, 50), glm::vec2(500, 50), glm::vec2(550, 300));
					QuitDraw();
					break;
				}
				case 7:
				{
					correctChoice = true;
					Clear;
					Drawing;
					/// This line draws a triangle with the parameters set for A, B, C, and D.
					Triangle(glm::vec2(100, 400), glm::vec2(300, 100), glm::vec2(500, 400));
					QuitDraw();
					break;
				}
				case 8:
				{
					correctChoice = true;
					Clear;
					Drawing;
					/// This line draws a circle with the parameters set for the centre of the circle, and its radius.
					Circle(glm::vec2(320, 240), 50);
					QuitDraw();
					break;
				}
				case 0: ///< Case 0: Quitting the menu
				{
					Clear;
					correctChoice = true;
					quitMenu = true; ///< The user has decided to quit the menu, so we need to change the boolean.
					break;
				}
				default: ///< Incorrect input case, displays a message and asks again for input.
				{
					Clear;
					std::cout << "Incorrect input, please try again.\n\n";
					break;
				}
			}
		}
	}
}

/// This menu is for drawing filled 2D shapes.
void FilledShapesMenu()
{
	bool quitMenu = false;
	int choice;

	while (!quitMenu)
	{
		bool correctChoice = false;
		while (!correctChoice)
		{
			std::cout << "Choose what would you like to view:\n";
			std::cout << "1. Square\n";
			std::cout << "2. Triangle\n";
			std::cout << "3. Circle\n";
			std::cout << "0. Quit menu\n\n";

			std::cin >> choice;
			switch (choice)
			{
				case 1:
				{
					correctChoice = true;
					Clear;
					Drawing;
					/// This line draws a filled square with the parameters set for A, B, C and D.
					FilledRectangle(glm::vec2(200, 200), glm::vec2(400, 200), glm::vec2(400, 400), glm::vec2(200, 400));
					QuitDraw();
					break;
				}
				case 2:
				{
					correctChoice = true;
					Clear;
					Drawing;
					/// This line draws a filled triangle with the parameters set for A, B and C.
					FilledTriangle(glm::vec2(100, 400), glm::vec2(300, 100), glm::vec2(500, 400));
					QuitDraw();
					break;
				}
				case 3:
				{
					correctChoice = true;
					Clear;
					Drawing;
					/// This line draws a filled circle with the parameters set for the centre of the circle, and its radius.
					FilledCircle(glm::vec2(320, 240), 50);
					QuitDraw();
					break;
				}
				case 0: ///< Case 0: Quitting the menu
				{
					correctChoice = true;
					quitMenu = true; ///< The user has decided to quit the menu, so we need to change the boolean.
					Clear;
					break;
				}
				default: ///< Incorrect input case, displays a message and asks again for input.
				{
					Clear;
					std::cout << "Incorrect input, please try again.\n\n";
					break;
				}
			}
		}
	}
}

/// This menu is for drawing fractal sets.
void FractalSetsMenu()
{
	bool quitMenu = false;
	int choice;

	while (!quitMenu)
	{
		bool correctChoice = false;
		while (!correctChoice)
		{
			std::cout << "Choose what would you like to view:\n";
			std::cout << "1. Cantor Set\n";
			std::cout << "2. Sierpinski Triangle\n";
			std::cout << "3. Mandlebrot Set\n";
			std::cout << "0. Quit menu\n\n";

			std::cin >> choice;
			switch (choice)
			{
				case 1:
				{
					correctChoice = true;
					Clear;
					Drawing;
					/** This line draws the Cantor set, with the starting point being (0,200),
					 *  and the initial line length being 640. */
					Cantor(glm::vec2(0, 200), 640);
					QuitDraw();
					break;
				}
				case 2:
				{
					correctChoice = true;
					Clear;
					Drawing;
					/** This line draws the Sierpinski triangle, with parameters set for the
					 *  A, B and C of the initial triangle, as well as an integer for the
					 *  wanted generation level of the fractal.
					 *
					 *  As stated in the documentation of the code, it is best to set the
					 *  generation level in the range [1-15]. */
					Sierpinski(glm::vec2(0, 480), glm::vec2(320, 0), glm::vec2(640, 480), 10);
					QuitDraw();
					break;
				}
				case 3:
				{
					correctChoice = true;
					Clear;
					Drawing;
					/// This line draws the Mandelbrot set.
					Mandelbrot();
					QuitDraw();
					break;
				}
				case 0: ///< Case 0: Quitting the menu
				{
					Clear;
					correctChoice = true;
					quitMenu = true; ///< The user has decided to quit the menu, so we need to change the boolean.
					break;
				}
				default: ///< Incorrect input case, displays a message and asks again for input.
				{
					Clear;
					std::cout << "Incorrect input, please try again.\n\n";
					break;
				}
			}
		}
	}
}

/** This is the main menu, which contains all of the sub-menus,
 *  and every drawing function outside the menus. */
void MainMenu()
{
	bool quitProgram = false;
	int choice;

	while (!quitProgram)
	{
		std::cout << "Welcome to Maciej's assignment framework.\n";
		std::cout << "Please, make yourself at home. :)\n\n";
		bool correctChoice = false;
		while (!correctChoice)
		{
			std::cout << "Choose what would you like to view:\n";
			std::cout << "1. Basic 2D shapes\n";
			std::cout << "2. Filled 2D shapes\n";
			std::cout << "3. Use of matrix transformations on a 2D square\n";
			std::cout << "4. Rotating 2D square\n";
			std::cout << "5. Bezier curves\n";
			std::cout << "6. Fractal sets\n";
			std::cout << "7. Rotating 3D shape with projection\n";
			std::cout << "\n\nTo quit the program, press X on the terminal...\n\n";
			std::cout << "or return to this main menu and type in 0 (zero)\n";
			std::cout << "into the terminal for a proper, controlled exit.\n\n";

			std::cin >> choice;
			switch (choice)
			{
				case 1:
				{
					correctChoice = true;
					Clear;
					/// This line calls the BasicShapesMenu().
					BasicShapesMenu();
					break;
				}
				case 2:
				{
					correctChoice = true;
					Clear;
					/// This line calls the FilledShapesMenu().
					FilledShapesMenu();
					break;
				}
				case 3:
				{
					correctChoice = true;
					Clear;
					/** This line calls SquareTransformations() with four 2D vectors as parameters, which
					 *  will be later on used for demonstrating matrix transformations. */
					SquareTransformations(glm::vec2(500, 300), glm::vec2(50, 450), glm::vec2(100, 300), glm::vec2(150, 350));
					Clear;
					break;
				}
				case 4:
				{
					correctChoice = true;
					Clear;
					/** This line calls RotatingSquare() with four 2D vectors as parameters set for
					 *  A, B, C and D. The square will rotate around the first vector. */
					RotatingSquare(glm::vec2(300, 200), glm::vec2(400, 200), glm::vec2(400, 300), glm::vec2(300, 300));
					Clear;
					break;
				}
				case 5:
				{
					correctChoice = true;
					Clear;
					Drawing;
					/** The lines below draw three Bezier curves, each with the two first parameters
					 *  as the start and end points of the wanted line, with the third parameter set
					 *  as the control point, creating the curvature of the line. */
					Bezier(glm::vec2(100, 400), glm::vec2(200, 100), glm::vec2(0, 0));
					Bezier(glm::vec2(200, 200), glm::vec2(400, 200), glm::vec2(300, 400));
					Bezier(glm::vec2(350, 450), glm::vec2(350, 50), glm::vec2(800, 225));
					QuitDraw();
					break;
				}
				case 6:
				{
					correctChoice = true;
					Clear;
					/// This line calls the FractalSetsMenu().
					FractalSetsMenu();
					break;
				}
				case 7:
				{
					correctChoice = true;
					Clear;
					/** This line calls RotatingPyramid() with five 3D vectors as parameters set for
					 *  A, B, C, D and E. The pyramid will rotate around the first vector as its origin. */
					RotatingPyramid(glm::vec3(300, 100, 100), glm::vec3(200, 300, 0), glm::vec3(400, 300, 0), glm::vec3(400, 300, 200), glm::vec3(200, 300, 200));
					Clear;
					break;
				}
				case 0: ///< Case 0: Quitting the menu
				{
					std::cout << "\nGoodbye! See you again!\n"; ///< The user has decided to quit the menu, so we need to change the boolean.
					correctChoice = true;
					quitProgram = true;
					break;
				}
				default: ///< Incorrect input case, displays a message and asks again for input.
				{
					Clear;
					std::cout << "Incorrect input, please try again.\n\n";
					break;
				}
			}
		}
	}
}

/** This function draws the drawings onto the MCG framework window and 
 *  waits for user input to continue. */
void QuitDraw()
{
	Drawn; ///< Displays a message stating that the drawing process has finished.
	std::cout << "Press TAB on the GLM window to go back to the menu.\n";

	MCG::ShowAndHold(); /**< This displays the drawings and waits for the user to input TAB to continue.
						*
						*   Yes, there have been a few small line changes in the MCG::ShowAndHold() and MCG::ProcessFrame() functions
						*   to stop them from destroying the windows and quitting.
						*
						*   Check the changes under "switch( incomingEvent.key.keysym.sym )". */

	MCG::SetBackground(glm::ivec3(255, 255, 255)); ///< Set the MCG framework's window background to white.
	Clear; ///< Clears the terminal window from text before quitting to one of the menus.
}
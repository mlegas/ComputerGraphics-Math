/** @file Menu.h
 *	@brief Function prototypes for menus and "after drawing" clean up.
 *
 *	As most of these functions are used in code only once, they could be
 *	just straight away implemented in the place where they are used, but for more
 *	code modularity and cleanness I divided them into separate functions.
 */

#pragma once
#ifndef _MENU_H_
#define _MENU_H_

/**	@brief This function displays a menu, allowing the user to choose a 2D shape to draw.
 *  @return Void.
 */
void BasicShapesMenu();
/**	@brief This function displays a menu, allowing the user to choose a filled 2D shape to draw.
 *  @return Void.
 */
void FilledShapesMenu();
/**	@brief This function displays a menu, allowing the user to choose a fractal set to draw.
 *  @return Void.
 */
void FractalSetsMenu();
/**	@brief This function displays the main menu, allowing the user to choose between menus/functions,
 *         as well as to quit the program in a controlled way.
 *  @return Void.
 */
void MainMenu();
/**	@brief This function displays the drawings and cleans up the terminal and the MCG framework
 *		     afterwards. Its sole purpose is to limit writing the same code again and again and again.
 *  @return Void.
 */
void QuitDraw();

#endif
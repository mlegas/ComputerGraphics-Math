/** @file Main.cpp
 *	@brief The main function, creating the MCG framework window, calling the MainMenu()
 *         and cleaning up after the user decides to quit the program.
 */

/// The MCG framework is included for the window initialization and later clean up of it.
#include "MCG_GFX_Lib.h"
/// The Menu.h is included for the use of the MainMenu() function.
#include "Menu.h"

int main( int argc, char *argv[] )
{
	/// Variable for storing window dimensions
	glm::ivec2 windowSize( 640, 480 );

	/** Call MCG::Init to initialise and create your window
	 *  Tell it what size you want the window to be */
	if( !MCG::Init( windowSize ) )
	{
		/** We must check if something went wrong
		 *  (this is very unlikely) */
		return -1;
	}

	/** Sets every pixel to the same colour
	 * parameters are RGBA, numbers are from 0 to 255 */
	MCG::SetBackground( glm::ivec3(255,255,255) );
	
	/// Calls the main menu.
	MainMenu();
	/// Destroys the MCG framework window after the user quits the MainMenu() function.
	MCG::Cleanup();
	/// After the clean up, the program waits for user input to finish quitting.
	system("PAUSE");
	return 0;
}

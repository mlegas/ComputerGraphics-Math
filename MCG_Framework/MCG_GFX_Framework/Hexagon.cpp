/** @file Hexagon.cpp
 *	@brief Implementation of a function drawing a hexagon.
 */

#include "Hexagon.h"
/// Line.h is included, as we need it for drawing the sides.
#include "Line.h"

/** Similarly to the FourSides() function case, this function calls the Line() 
 *  function six times to draw the sides of a hexagon. 
 *
 *  Initially based in the FourSides.cpp file, I created a separate file for it
 *  just to have better code modularity. */
void Hexagon(glm::vec2 const _p1, glm::vec2 const _p2, glm::vec2 const _p3, glm::vec2 const _p4, glm::vec2 const _p5, glm::vec2 const _p6)
{
	/// These calls create a hexagon shape by drawing each side.
	Line(_p1, _p2);
	Line(_p2, _p3);
	Line(_p3, _p4);
	Line(_p4, _p5);
	Line(_p5, _p6);
	Line(_p6, _p1);
}

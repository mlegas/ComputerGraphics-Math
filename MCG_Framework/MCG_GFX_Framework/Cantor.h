/** @file Cantor.h
 *	@brief Function prototype for drawing a Cantor set.
 */

#pragma once
#ifndef _CANTOR_H_
#define _CANTOR_H_

 /// This include is necessary for the prototype to compile properly, as the function takes a 2D vector from GLM as a parameter.
#include "GLM/vec2.hpp"

/** @brief This function recursively draws the Cantor set, taking as initial parameters a 2D vector (point), 
 *		     and a float named length, which will be the length of the first line created.
 *  @param _p1 A 2D vector.
 *  @param _length The length of the first line.
 *  @return Void.
 */
void Cantor(glm::vec2 _p1, float _length);

#endif
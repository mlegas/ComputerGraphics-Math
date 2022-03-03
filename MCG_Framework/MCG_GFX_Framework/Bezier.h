/** @file Bezier.h
 *	@brief Function prototype for drawing Bezier curves.
 */

#pragma once
#ifndef _BEZIER_H_
#define _BEZIER_H_

 /// This include is necessary for the prototype to compile properly, as the function takes 2D vectors from GLM as parameters.
#include "GLM/vec2.hpp"

/** @brief This function creates a Bezier curve between two 2D vectors (points), taking 
 *		   a 2D vector as a parameter on which the curvature is based.
 *  @param _a First vector.
 *  @param _b Second vector.
 *  @param _c The vector for the curvature.
 *  @return Void.
 */
void Bezier(glm::vec2 _a, glm::vec2 _b, glm::vec2 _c);

#endif
/** @file Circle.h
 *	@brief Function prototypes for circle drawing purposes.
 */

#pragma once
#ifndef _CIRCLE_H_
#define _CIRCLE_H_

/// This include is necessary for the prototypes to compile properly, as the functions take a 2D vector from GLM as a parameter.
#include "GLM/vec2.hpp"

/** @brief This function draws a circle with the specified radius.
 *  @param _centre A 2D vector (position), specifying the location of the centre of the circle.
 *  @param _radius The length of the radius.
 *  @return Void.
 */
void Circle(glm::vec2 _centre, int _radius);

/** @brief This function draws a filled circle with the specified radius.
 *  @param _centre A 2D vector (position), specifying the location of the centre of the circle.
 *  @param _radius The length of the radius.
 *  @return Void.
 */
void FilledCircle(glm::vec2 _centre, int _radius);

#endif
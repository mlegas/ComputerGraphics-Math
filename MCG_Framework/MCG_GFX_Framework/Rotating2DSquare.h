/** @file Rotating2DSquare.h
 *  @brief Function prototype for drawing a rotating 2D square.
 */

#pragma once
#ifndef _ROTATING2DSQUARE_H_
#define _ROTATING2DSQUARE_H_

/// This include is necessary for the function to compile properly, as it takes 2D vectors from GLM as parameters.
#include "GLM/vec2.hpp"

/** @brief This function draws and animates a 2D square, rotating it around a vector.
 *  @param _p1 First 2D vector (A). Also the origin of the rotation.
 *  @param _p2 Second 2D vector (B).
 *  @return Void.
 */
void RotatingSquare(glm::vec2 _p1, glm::vec2 _p2, glm::vec2 _p3, glm::vec2 _p4);

#endif
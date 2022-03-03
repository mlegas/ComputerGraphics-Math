/** @file Sierpinski.h
 *  @brief Function prototypes for drawing a Sierpinski triangle.
 */

#pragma once
#ifndef _SIERPINSKI_H_
#define _SIERPINSKI_H_

/// This include is necessary for the function to compile properly, as it takes 2D vectors from GLM as parameters.
#include "GLM/vec2.hpp"

/** @brief This function recursively draws the Sierpinski triangle, taking 
 *         three 2D vectors as the points of the first triangle.
 *  @param _x First 2D vector (A).
 *  @param _y Second 2D vector (B).
 *  @param _z Third 2D vector (C).
 *  @param generation This parameter controls till which generation level should
 *                    the function continue. Please do not set it over 15, as the
 *                    X and Y values will get massively low, causing the CPU to lag
 *                    while trying to draw them.
 *  @return Void.
 */
void Sierpinski(glm::vec2 _x, glm::vec2 _y, glm::vec2 _z, int generation);
/** @brief This function returns a midpoint between two 2D vectors.
 *  @param _p1 First 2D vector (A).
 *  @param _p2 Second 2D vector (B).
 *  @return A glm::vec2, being the midpoint between _p1 and _p2.
 */
glm::vec2 Midpoint(glm::vec2 _p1, glm::vec2 _p2);

#endif
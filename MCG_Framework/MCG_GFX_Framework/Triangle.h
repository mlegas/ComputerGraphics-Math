/** @file Triangle.h
 *  @brief Function prototypes for drawing a triangle.
 */

#pragma once
#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

/// This include is necessary for the function to compile properly, as it takes 2D vectors from GLM as parameters.
#include "GLM/vec2.hpp"

/** @brief This function draws a 2D triangle, using three 2D vectors, between which lines are drawn to create a "wire-frame".
 *  @param _p1 First 2D vector (A).
 *  @param _p2 Second 2D vector (B).
 *  @param _p3 Third 2D vector (C).
 *  @return Void.
 */
void Triangle(glm::vec2 const _p1, glm::vec2 const _p2, glm::vec2 const _p3);
/** @brief This function draws a 2D triangle, using three 2D vectors, between which lines are drawn to fill the shape.
 *  @param _p1 First 2D vector (A).
 *  @param _p2 Second 2D vector (B).
 *  @param _p3 Third 2D vector (C).
 *  @return Void.
 */
void FilledTriangle(glm::vec2 const _p1, glm::vec2 const _p2, glm::vec2 const _p3);

#endif
/** @file Line.h
 *  @brief Function prototype for drawing a line using Bresenham's line algorithm.
 */

#pragma once
#ifndef _LINE_H_
#define _LINE_H_

/// This include is necessary for the prototype to compile properly, as the function takes 2D vectors from GLM as parameters.
#include "GLM/vec2.hpp"

/**
 * @brief This function creates a line between two 2D vectors (points) using Bresenham's line algorithm.
 * @param _p1 First vector.
 * @param _p2 Second vector.
 */
void Line(glm::vec2 const _p1, glm::vec2 const _p2);

#endif
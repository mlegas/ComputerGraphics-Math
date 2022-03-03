/** @file FourSides.h
 *  @brief Function prototypes for drawing a four-sided shape.
 */

#pragma once
#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

/// This include is necessary for the prototypes to compile properly, as the functions take 2D vectors from GLM as parameters.
#include "GLM/vec2.hpp"

/** @brief This function draws a four-sided figure, using four 2D vectors, between which lines are drawn to create a "wire-frame".
 *  @param _p1 First 2D vector (A).
 *  @param _p2 Second 2D vector (B).
 *  @param _p3 Third 2D vector (C).
 *  @param _p4 Fourth 2D vector (D).
 *  @return Void.
 */
void FourSides(glm::vec2 const _p1, glm::vec2 const _p2, glm::vec2 const _p3, glm::vec2 const _p4);

/** @brief This function draws a filled four-sided figure, using four 2D vectors, between which lines are drawn to fill the shape.
 *  @param _p1 First 2D vector (A).
 *  @param _p2 Second 2D vector (B).
 *  @param _p3 Third 2D vector (C).
 *  @param _p4 Fourth 2D vector (D).
 *  @return Void.
 */
void FilledRectangle(glm::vec2 const _p1, glm::vec2 const _p2, glm::vec2 const _p3, glm::vec2 const _p4);

#endif
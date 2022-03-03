/** @file SquareTransformations.h
 *  @brief Function prototype for demonstrating matrix transformations on a 2D square.
 */

#pragma once
#ifndef _SQUARETRANSFORMATIONS_H_
#define _SQUARETRANSFORMATIONS_H_

/// This include is necessary for the function to compile properly, as it takes 2D vectors from GLM as parameters.
#include "GLM/vec2.hpp"

/** @brief This function draws a 2D square and performs matrix
 *         transformations on it. It has been created to ensure
 *         that the assignment's criteria have been met.
 *  @param _p1 First 2D vector (A).
 *  @param _p2 Second 2D vector (B).
 *  @param _p3 Third 2D vector (C).
 *  @param _p4 Fourth 2D vector (D).
 *  @return Void.
 */
void SquareTransformations(glm::vec2 const _p1, glm::vec2 const _p2, glm::vec2 const _p3, glm::vec2 const _p4);

#endif
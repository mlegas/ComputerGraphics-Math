/** @file Hexagon.h
 *	@brief Function prototype for drawing a hexagon.
 */

#pragma once
#ifndef _HEXAGON_H_
#define _HEXAGON_H_

 /// This include is necessary for the prototype to compile properly, as the function takes 2D vectors from GLM as parameters.
#include "GLM/vec2.hpp"

/** @brief This function draws a hexagon, using six 2D vectors, between which lines are drawn to create a "wire-frame".
 *  @param _p1 First 2D vector (A).
 *  @param _p2 Second 2D vector (B).
 *  @param _p3 Third 2D vector (C).
 *  @param _p4 Fourth 2D vector (D).
 *  @param _p5 Fifth 2D vector (E).
 *  @param _p6 Sixth 2D vector (F).
 */
void Hexagon(glm::vec2 const _p1, glm::vec2 const _p2, glm::vec2 const _p3, glm::vec2 const _p4, glm::vec2 const _p5, glm::vec2 const _p6);

#endif

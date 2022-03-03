/** @file Rotating3DPyramid.h
 *  @brief Function prototype for drawing a rotating 3D pyramid.
 */

#pragma once
#ifndef _ROTATING3DPYRAMID_H_
#define _ROTATING3DPYRAMID_H_

/// This include is necessary for the function to compile properly, as it takes 3D vectors from GLM as parameters.
#include "GLM/vec3.hpp"

/** @brief This function draws and animates a 3D pyramid, rotating it around its own axis.
 *  @param _p1 First 3D vector (A). Also the origin of the rotation.
 *  @param _p2 Second 3D vector (B).
 *  @param _p3 Third 3D vector (C).
 *  @param _p4 Fourth 3D vector (D).
 *  @param _p5 Fifth 3D vector (E).
 *  @return Void.
 */
void RotatingPyramid(glm::vec3 _p1, glm::vec3 _p2, glm::vec3 _p3, glm::vec3 _p4, glm::vec3 _p5);

#endif
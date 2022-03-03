/** @file Rotating3DPyramid.cpp
 *	@brief Implementation of a function drawing and rotating a 3D pyramid.
 *
 *  This function draws and animates a 3D pyramid around one of its points, using
 *  GLM's functions for perspective, projection, view and rotation.
 *
 *  I used a lot from these sources to help me understand how does
 *  the camera and 3D projection work:
 *  http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/
 *  https://learnopengl.com/Getting-started/Camera
 *  https://stackoverflow.com/questions/35261192/how-to-use-glmproject-to-get-the-coordinates-of-a-point-in-world-space
 *  https://gamedev.stackexchange.com/questions/98226/how-can-i-set-up-an-intuitive-perspective-projection-view-matrix-combination-in
 */
#include "Rotating3DPyramid.h"
/// FourSides.h is included for drawing the base of the pyramid.
#include "FourSides.h"
/// Line.h is included, as we need it for drawing the sides.
#include "Line.h"
/// MCG framework is included, as we need it to make the background white with each iteration.
#include "MCG_GFX_Lib.h"
/// iostream is included to display a message.
#include <iostream>

void RotatingPyramid(glm::vec3 const _p1, glm::vec3 const _p2, glm::vec3 const _p3, glm::vec3 const _p4, glm::vec3 const _p5)
{
	std::cout << "Press TAB on the GLM window to go back to the menu.\n";

	/// The lines below create 4D vectors from the points passed to the function.
	glm::vec4 p1 = glm::vec4(_p1.x, _p1.y, _p1.z, 1);
	glm::vec4 p2 = glm::vec4(_p2.x, _p2.y, _p2.z, 1);
	glm::vec4 p3 = glm::vec4(_p3.x, _p3.y, _p3.z, 1);
	glm::vec4 p4 = glm::vec4(_p4.x, _p4.y, _p4.z, 1);
	glm::vec4 p5 = glm::vec4(_p5.x, _p5.y, _p5.z, 1);

	glm::vec4 vertices[5] = { p1,p2,p3,p4,p5 }; ///< An array of the vertices.
	glm::vec3 verticesToDraw[5]; ///< This array will later contain the vertices that have been rotated.

	glm::vec4 origin = p1; ///< Sets the origin of the rotation to the tip of the pyramid (p1).

	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3((origin.x), (origin.y), (origin.z))); /**< This is the model later used for the rotation.  
																									   *   It is translated to the origin, as that is where
																									   *   the rotation will take place. */

	glm::mat4 projection = glm::perspective(glm::radians(70.0f), 640.0f / 480.0f, 0.1f, 100.f); /**< This line sets the projection matrix, with a fov of 70 degrees
																								 *   and the aspect ratio of the window. */
	/// The lines below set the camera.
	glm::mat4 view = glm::lookAt(
		glm::vec3(0, 0, 1), ///< This is the origin of the camera.
		glm::vec3(1, 1, 0), ///< This is the direction of the camera, where the camera looks at.
		glm::vec3(0, 1, 0)); ///< This sets the camera to look up.

	float angle = 0.0f; ///< A float used later on for the angle.

	while (MCG::ProcessFrame()) ///< This while loop will rotate the pyramid until the users decides to exit.
	{
		MCG::SetBackground(glm::ivec3(255, 255, 255)); /**< Sets the background to be white with each rotation, as we do not want
													    *   the animation to leave traces. */

		angle += 0.01f; ///< Adds a small degree with each iteration.

		/// This if statement sets the angle to 0 if it is equal to 360, as that means a full rotation has been completed.
		if (angle >= 360.0f)
		{
			angle = 0.0f;
		}

		for (int i = 0; i < 5; i++)
		{
			glm::mat4 rotation = glm::rotate(model, angle, glm::vec3(0.0f, 1.0f, 0.0f)); /**< This line creates the rotation matrix, using the glm::rotate function.
																						  *   The parameters are the model, the angle which is changed with each iteration,
																						  *   and the axis on which the rotation is applied, which is Y in this case. */

			glm::vec4 rotatedVertex = (rotation * (vertices[i] - origin) + origin); /**< This line rotates the vertices of the pyramid around the origin. 
																					 *   The origin is substracted and added as we need to translate the points
																					 *   for a proper rotation. */
			
			verticesToDraw[i] = projection * view * rotatedVertex; /**< This line applies the projection and the camera view to the vertices, giving us
                                                                    *   aspect ratio, an angle from the camera and projection. */
		}

		/// This for loop draws the lines from the origin point (p1) to the rest of the vertices.
		for (int j = 1; j < 5; j++)
		{
			Line(glm::vec2(verticesToDraw[0].x, verticesToDraw[0].y), glm::vec2(verticesToDraw[j].x, verticesToDraw[j].y));
		}
		
		/// This line below draws the base of the pyramid.
		FourSides(verticesToDraw[1], verticesToDraw[2], verticesToDraw[3], verticesToDraw[4]);
	}
	MCG::SetBackground(glm::vec3(255, 255, 255)); ///< This line sets the background to be white when the user quits the function.
}
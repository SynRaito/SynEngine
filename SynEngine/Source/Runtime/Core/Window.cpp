#include "Window.h"
#include <iostream>

void Syn::Core::Window::Update()
{
	glfwMakeContextCurrent(glfwWindow);

	if (glfwWindowShouldClose(glfwWindow))
	{
		glfwTerminate();

		return;
	}
	
	/* Render here */

	glClearColor(1, 1, 1, 1);

	glClear(GL_COLOR_BUFFER_BIT);

	/* Swap front and back buffers */
	glfwSwapBuffers(glfwWindow);

	/* Poll for and process events */
	glfwPollEvents();

}

void Syn::Core::Window::Close()
{
	glfwSetWindowShouldClose(glfwWindow, true);
}
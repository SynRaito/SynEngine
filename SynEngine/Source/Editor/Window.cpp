#include "Window.h"

void Syn::Editor::Window::Update()
{
	glfwMakeContextCurrent(m_glfwWindow);

	if (glfwWindowShouldClose(m_glfwWindow))
	{
		glfwTerminate();
	}
	
	/* Render here */

	glClearColor(1, 1, 1, 1);

	glClear(GL_COLOR_BUFFER_BIT);

	/* Swap front and back buffers */
	glfwSwapBuffers(m_glfwWindow);

	/* Poll for and process events */
	glfwPollEvents();

}
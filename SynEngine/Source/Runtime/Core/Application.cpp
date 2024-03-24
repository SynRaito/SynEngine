#include "Application.h"
#include <iostream>
#include "GLFW/glfw3.h"

namespace Syn {

	Application::Application()
	{

	}

	Application::~Application()
	{
	}
	
	void Application::Run() {
		glfwInit();

		GLFWwindow* window;
		window = glfwCreateWindow(800, 400, "Test", NULL, NULL);

		glfwMakeContextCurrent(window);

		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			glClearColor(1, 1, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}

		glfwTerminate();
	}

}
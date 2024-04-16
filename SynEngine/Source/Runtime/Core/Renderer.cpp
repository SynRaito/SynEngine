
#include "Renderer.h"
#include <glad.h>
#include <glfw3.h>

Syn::Core::Renderer::Renderer()
{
	glfwInit();
}

bool Syn::Core::Renderer::InitializeRenderer(Syn::Core::Window& window)
{
	glfwMakeContextCurrent(window.GlfwWindow());

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}
}
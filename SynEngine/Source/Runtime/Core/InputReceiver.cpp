#include "InputReceiver.h"
#include "Window.h"
#include <glad.h>
#include <glfw3.h>

void Syn::Core::InputReceiver::ProcessInputs(Syn::Core::Window* window)
{
	if (glfwGetKey(window->GlfwWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		//TODO: Trigger Input Event
	}
}
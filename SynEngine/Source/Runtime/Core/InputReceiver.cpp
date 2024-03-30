#include "InputReceiver.h"

void Syn::Core::InputReceiver::ProcessInputs(Syn::Core::Window* window)
{
	if (glfwGetKey(window->GlfwWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		//...
	}
}
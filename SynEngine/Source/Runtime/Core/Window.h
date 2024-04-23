#pragma once

#include <glad.h>
#include <glfw3.h>
#include "Core.h"

class GLFWwindow;

namespace Syn::Core {

	class SYN_API Window {
	
	public:

		Window(int width, int height, const char* name = "");
		

	private:
		int width;
		int height;
		GLFWwindow* glfwWindow;

		public:
			GLFWwindow* GlfwWindow();

	public:
		void Update(float deltaTime);

		void Close();
	};

}
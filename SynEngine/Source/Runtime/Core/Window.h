#pragma once

#include "Core.h"
#include <vector>
#include <glad.h>
#include <glfw3.h>

namespace Syn::Core {

	class SYN_API Window {

	public:

		Window(int width, int height, const char* name = "") : width(width), height(height)
		{
			glfwWindow = glfwCreateWindow(width, height, name, NULL, NULL);
		}

	private:
		int width;
		int height;
		GLFWwindow* glfwWindow;

		public:
			inline GLFWwindow* GlfwWindow() { return glfwWindow; }

	public:
		void Update();

		void Close();
	};

}
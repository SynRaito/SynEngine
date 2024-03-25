#pragma once

#include "../Runtime/Core/Core.h"
#include <vector>
#include <glfw3.h>

namespace Syn::Editor {

	class SYN_API Window {

	public:

		Window(int width, int height, const char* name = "") : m_width(width), m_height(height)
		{
			m_glfwWindow = glfwCreateWindow(width, height, name, NULL, NULL);

			if (m_glfwWindow) {
			}
		}

	private:
		int m_width;
		int m_height;
		GLFWwindow* m_glfwWindow;

	public:
		void Update();
	};

}
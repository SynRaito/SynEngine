#include "Application.h"

namespace Syn {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}
	
	void Application::Run() {

		glfwInit();

		EditorInstance.CreateWindow(1000, 1000, "Test");

		//Game Loop
		while (true) {
			//Render Loop
			EditorInstance.Render();
		}
	}

}
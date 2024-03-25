#pragma once

#include "Core.h"
#include <iostream>
#include <vector>
#include <glfw3.h>
#include "../../Editor/Window.h"
#include "../../Developer/Event/Event.h"
#include "../../Editor/EditorInstance.h"

namespace Syn {

	class SYN_API Application
	{
	private:
		Syn::Editor::EditorInstance EditorInstance;
	public:
		Application();
		virtual ~Application();

		void Run();
		void Test(int);
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}
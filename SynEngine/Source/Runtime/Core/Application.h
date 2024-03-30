#pragma once

#include <iostream>
#include <vector>
#include "Window.h"
#include "Renderer.h"
#include "Core.h"
#include "GameInstance.h"

namespace Syn {

	class SYN_API Application
	{
	private:
		Syn::Core::GameInstance GameInstance;
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}
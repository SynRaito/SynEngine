#pragma once

#include "Core.h"

namespace Syn {

	class SYN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}
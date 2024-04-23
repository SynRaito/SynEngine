#pragma once

#include "Core.h"
#include "GameInstance.h"
#include "../../Developer/Time/Time.h"

namespace Syn {

	class SYN_API Application
	{
	private:
		Syn::Core::GameInstance gameInstance;
		Syn::Time time;

	public:
		Application();
		virtual ~Application();

		void Run();
		
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}
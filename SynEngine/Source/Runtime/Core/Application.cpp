#include "Application.h"
#include "../Engine/PTR.h"

namespace Syn {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() {

		// TEST PURPOSES

		GameInstance.CreateWindow(1000, 1000, "Test");

		//TEST PURPOSES

		//Game Loop
		while (true) {

			//Render Loop			
			GameInstance.Update();

			//Garbage Collection
			GameInstance.GarbageCollector.VisitObjects();
		}
	}
}
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

		GameInstance.CreateNewWindow(1000, 1000, "Test");

		//TEST PURPOSES


		//Game Loop
		while (true) {
			//Input
			GameInstance.inputReceiver.ProcessInputs(GameInstance.window);
			
			//Render Loop
			GameInstance.Update();

			//Garbage Collection
			GameInstance.garbageCollector.VisitObjects();
		}
	}
}
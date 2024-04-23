#include "Application.h"
#include "../Engine/PTR.h"
#include "../../Developer/Time/Time.h"

namespace Syn {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}



	void Application::Run() {

		// TEST PURPOSES

		gameInstance.CreateNewWindow(1000, 1000, "Test");

		//TEST PURPOSES


		//Game Loop
		while (true) {
			//Delta Time Evaluation
			time.EvaluateDeltaTime();

			//Input
			gameInstance.inputReceiver.ProcessInputs(gameInstance.window);
			
			//Render Loop
			gameInstance.Update(time.DeltaTime());

			//Garbage Collection
			gameInstance.garbageCollector.VisitObjects();
		}
	}
}
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

		class Test : public Syn::Core::Object {

		public:

			void TestFuncEnter() {
				std::cout << "Enter";
			}

			void TestFuncEsc() {
				std::cout << "Esc";
			}
		};

		Syn::Engine::PTR<Test> test = GameInstance.CreateGameObject<Test>();

		GameInstance.InputReceiver.RegisterEvent(Syn::Core::InputKey::KeyCode::ENTER, Syn::Core::InputKey::KeyState::Pressed, test, test.Bind(&Test::TestFuncEnter));
		GameInstance.InputReceiver.RegisterEvent(Syn::Core::InputKey::KeyCode::ESCAPE, Syn::Core::InputKey::KeyState::Released, test, test.Bind(&Test::TestFuncEsc));
		GameInstance.InputReceiver.UnregisterEvent(Syn::Core::InputKey::KeyCode::ENTER, Syn::Core::InputKey::KeyState::Pressed, test, test.Bind(&Test::TestFuncEnter));

		//TEST PURPOSES

		//Game Loop
		while (true) {
			//Input
			GameInstance.InputReceiver.ProcessInputs(GameInstance.Window);
			
			//Render Loop			
			GameInstance.Update();

			//Garbage Collection
			GameInstance.GarbageCollector.VisitObjects();
		}
	}
}
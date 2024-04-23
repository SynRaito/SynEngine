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

			void TestFuncInt(int i) {
				std::cout << i;
			}

			void TestFuncEsc() {
				std::cout << "Esc";
			}
		};

		class Test2 : public Test {
		public:
			void Deneme() {
				std::cout << "Deneme";
			}
		};
		void(Test::*ptr)() = static_cast<void(Test::*)()>(&Test2::Deneme);
		Test2 t2;
		Test t = static_cast<Test>(t);
		(t.*ptr)();

		DYNAMIC_LINKED_EVENT_ONE_PARAM(int) event1;

		Syn::Engine::PTR<Test> testObj = GameInstance.CreateGameObject<Test>();

		event1.Register(testObj, WRAP_LINKED_EVENT_FUNCTION_ONE_PARAM(&Test::TestFuncInt,int));

		event1.Trigger(10);
		
		GameInstance.InputReceiver.RegisterEvent(Syn::Core::InputKey::KeyCode::ESCAPE, Syn::Core::InputKey::KeyState::Released, testObj, WRAP_LINKED_EVENT_FUNCTION(&Test::TestFuncEsc));
		GameInstance.InputReceiver.UnregisterEvent(Syn::Core::InputKey::KeyCode::ESCAPE, Syn::Core::InputKey::KeyState::Released, testObj, WRAP_LINKED_EVENT_FUNCTION(&Test::TestFuncEsc));

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
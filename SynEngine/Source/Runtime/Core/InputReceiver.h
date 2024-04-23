#pragma once

#include "Core.h"
#include <map>
#include "InputKey.h"
#include "Window.h"

namespace Syn::Core {
	class SYN_API InputReceiver  {

	private:
		std::map<int,InputKey> InputKeys;
		
	private:
		void HandleInputState(Syn::Core::Window &window, std::pair<const int , InputKey> Pair);
		
	public:
		InputReceiver();

		void ProcessInputs(Window* window);

		/**
		 * Example Usage : RegisterEvent(KeyCode, KeyState, obj, DYNAMIC_LINKED_EVENT(&Syn::Core::Obj::TestFunc));
		 * obj must be PTR
		 **/
		void RegisterEvent(InputKey::KeyCode keyCode, InputKey::KeyState keyState, Engine::PTR<Core::Object> obj, void (Syn::Core::Object::* func)());
		void UnregisterEvent(InputKey::KeyCode keyCode, InputKey::KeyState keyState, Engine::PTR<Object> obj, void (Syn::Core::Object::* func)());
		
		bool GetKeyDown(InputKey::KeyCode KeyCode);
		bool GetKeyUp(InputKey::KeyCode KeyCode);
		bool GetKey(InputKey::KeyCode KeyCode);
	};
}
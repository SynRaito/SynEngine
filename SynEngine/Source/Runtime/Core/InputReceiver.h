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
		 * Example Usage : Register(keyCode, keyState, obj, PTR<T>::obj.Bind(&Syn::Core::TestFunc));
		 * obj must be derived from Object
		 **/
		void RegisterEvent(InputKey::KeyCode keyCode, InputKey::KeyState keyState, Engine::PTR<Core::Object> obj, std::function<void()> func);
		void UnregisterEvent(InputKey::KeyCode keyCode, InputKey::KeyState keyState, Engine::PTR<Object> obj, std::function<void()> func);
	};
}
#pragma once

#include "Core.h"
#include "InputKey.h"
#include "Window.h"

namespace Syn::Core {
	class SYN_API InputReceiver  {

	public:
		InputReceiver() = default;

		void ProcessInputs(Window* window);

		void RegisterEvent(InputKey::KeyCode KeyCode, InputKey::KeyState KeyState);
	};
}
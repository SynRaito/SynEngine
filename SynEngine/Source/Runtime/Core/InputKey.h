#pragma once

#include "Core.h"

namespace Syn::Core {

	class SYN_API InputKey {

		
	public :
		enum class KeyCode : char {
			Esc
		};

		enum class KeyState : char {
			None,
			Pressed,
			Hold,
			Released
		};

	public:
		InputKey(KeyCode KeyCode);

	private:
		KeyCode keyCode;
		KeyState state;

	public:
		inline void SetState(KeyState KeyState) { state = KeyState; }
		KeyState State() { return state; }
	};
}
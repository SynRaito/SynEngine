#pragma once

#include "../../Developer/Event/Event.h"
#include "Core.h"
#include <glad.h>
#include <glfw3.h>
#include "Window.h"

namespace Syn::Core {
	class SYN_API InputReceiver {

	public:
		InputReceiver() = default;

	private:

	public:
		void ProcessInputs(Syn::Core::Window* window);

		Syn::LinkedEvent<Syn::Core::Window> OnEscape;
	};

}
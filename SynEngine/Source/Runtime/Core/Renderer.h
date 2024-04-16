#pragma once

#include <iostream>
#include "Window.h"
#include "Core.h"

namespace Syn::Core {

	class SYN_API Renderer {

	public:
		Renderer();

		bool InitializeRenderer(Syn::Core::Window&);
	};
}
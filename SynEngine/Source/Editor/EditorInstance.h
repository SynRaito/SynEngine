#pragma once

#include "../Runtime/Core/Core.h"
#include <vector>
#include "Window.h"

namespace Syn::Editor {

	class SYN_API EditorInstance
	{
	public:
		EditorInstance() = default;
		~EditorInstance();
	private:
		void RenderWindows();

	public:
		std::vector<Syn::Editor::Window*> Windows;

		void CreateWindow(int width, int height, const char* name = "");

		void Render();
	};
}
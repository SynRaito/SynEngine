#pragma once

#include "Core.h"
#include "Renderer.h"
#include <vector>
#include "Window.h"
#include "InputReceiver.h"

namespace Syn::Core {

	class SYN_API GameInstance
	{
	public:
		GameInstance();
		~GameInstance();

	private:

	public:
		Syn::Core::Window* Window;
		Syn::Core::Renderer* Renderer;
		Syn::Core::InputReceiver InputReceiver;

		void CreateWindow(int width, int height, const char* name = "");
		void SetViewport(int width, int height);
		void HandleInputRegisters();

		void Update();
	};
}
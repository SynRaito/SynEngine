#include "GameInstance.h"
#include <iostream>
#include <glad.h>
#include <glfw3.h>

//Callback Decls
void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);
//

Syn::Core::GameInstance::GameInstance()
{
	Renderer = new Syn::Core::Renderer();
}

Syn::Core::GameInstance::~GameInstance()
{
	delete Window;
	delete Renderer;
}

void Syn::Core::GameInstance::CreateWindow(int width, int height, const char* name)
{
	Syn::Core::Window* NewWindow = new Syn::Core::Window(width, height, name);

	if (NewWindow) {
		Window = NewWindow;

		Renderer->InitializeRenderer(*Window);
		SetViewport(width, height);
		glfwSetFramebufferSizeCallback(Window->GlfwWindow(), FrameBufferSizeCallback);
		HandleInputRegisters();
	}
	else
	{
		std::cout << "Window cannot be initialized!" << std::endl;
	}
}

void Syn::Core::GameInstance::SetViewport(int width, int height)
{
	glViewport(0,0,width, height);
}

void Syn::Core::GameInstance::HandleInputRegisters()
{
	//InputReceiver.OnEscape.Register(*Window, &Window::Close);
}

void Syn::Core::GameInstance::Update()
{
	if (Window) {
		InputReceiver.ProcessInputs(Window);
		Window->Update();
	}
	else
	{
		std::cout << "Window is not created! Use CreateWindow to specift and create the one." << std::endl;
	}
}

//Callbacks

void FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
#include "GameInstance.h"
#include <iostream>
#include <glad.h>
#include <glfw3.h>
#include "../../Developer/Log/Log.h"

//Callback Decls
void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);
//

Syn::Core::GameInstance::GameInstance()
{
	renderer = new Syn::Core::Renderer();
}

Syn::Core::GameInstance::~GameInstance()
{
	delete window;
	delete renderer;
}

void Syn::Core::GameInstance::CreateNewWindow(int width, int height, const char* name)
{
	Syn::Core::Window* NewWindow = new Syn::Core::Window(width, height, name);

	if (NewWindow) {
		window = NewWindow;

		renderer->InitializeRenderer(*window);
		SetViewport(width, height);
		glfwSetFramebufferSizeCallback(window->GlfwWindow(), FrameBufferSizeCallback);
	}
	else
	{
		SYN_ENGINE_ERROR("Window cannot be initialized!");
	}
}

void Syn::Core::GameInstance::SetViewport(int width, int height)
{
	glViewport(0,0,width, height);
}

void Syn::Core::GameInstance::Update(float deltaTime)
{
	if (window) {
		for (Syn::Engine::PTR<GameObject> gameObject : gameObjects)
		{
			gameObject->Update(deltaTime);
		}
		window->Update(deltaTime);
	}
	else
	{
		SYN_ENGINE_ERROR("Window is not created! Use CreateNewWindow to specify and create the one.");
	}
}

//Callbacks

void FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
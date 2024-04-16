#pragma once

#include "Core.h"
#include "Renderer.h"
#include <vector>
#include "Window.h"
#include "InputReceiver.h"
#include "GameObject.h"
#include "../Engine/PTR.h"

namespace Syn::Core {

	class SYN_API GameInstance
	{
	public:
		GameInstance();
		~GameInstance();

	private:
		std::vector<Syn::Core::GameObject> GameObjects;

	public:
		Syn::Core::Window* Window;
		Syn::Core::Renderer* Renderer;
		Syn::Core::InputReceiver InputReceiver;
		Syn::Engine::ObjectGC GarbageCollector;
		

		void CreateWindow(int width, int height, const char* name = "");
		void SetViewport(int width, int height);
		void HandleInputRegisters();

		/**
		 * \brief Creates New GameObject
		 * \tparam T Must be derived from GameObject
		 * \return New Object Reference, must be assign to non-reference type to be able to garbage collect.
		 */
		template<class T>
		Syn::Engine::PTR<T> CreateGameObject();
		
		void Update();
	};

	template<class T>
	inline Syn::Engine::PTR<T> Syn::Core::GameInstance::CreateGameObject()
	{
		Syn::Engine::PTR<T>* NewObject = new Syn::Engine::PTR<T>;
		
		GarbageCollector.AddObject(*NewObject);

		return *NewObject;
	}

}
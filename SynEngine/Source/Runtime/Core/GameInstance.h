#pragma once

#include "Core.h"
#include "Renderer.h"
#include <vector>
#include "Window.h"
#include "InputReceiver.h"
#include "GameObject.h"
#include "../Engine/PTR.h"
#include "../../Developer/Log/Log.h"

namespace Syn::Core {

	class SYN_API GameInstance
	{
	public:
		GameInstance();
		~GameInstance();

	private:
		std::vector<Syn::Engine::PTR<Syn::Core::GameObject>> gameObjects;

	public:
		Syn::Core::Window* window;
		Syn::Core::Renderer* renderer;
		Syn::Core::InputReceiver inputReceiver;
		Syn::Engine::ObjectGC garbageCollector;
		

		void CreateNewWindow(int width, int height, const char* name = "");
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
		
		static_cast<Syn::Engine::PTR<GameObject>>(*NewObject).Get().Begin();

		garbageCollector.AddObject(*NewObject);
		gameObjects.push_back(*NewObject);

		return *NewObject;
	}

}
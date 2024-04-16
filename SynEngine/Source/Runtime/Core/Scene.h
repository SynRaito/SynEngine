#pragma once

#include "Core.h"
#include <vector>
#include "GameObject.h"
#include "InputReceiver.h"

namespace Syn::Core {

	class SYN_API Scene {
	public:
		Scene();
		~Scene();

	private:
		std::vector<Syn::Core::GameObject*>* m_gameObjects;
	public:
		void Update();

	};
}
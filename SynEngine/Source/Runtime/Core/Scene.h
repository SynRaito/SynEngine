#pragma once

#include "Core.h"
#include <vector>
#include "GameObject.h"

class GameObject;

namespace Syn {

	class SYN_API Scene {
	public:
		Scene();
		~Scene();

	private:
		std::vector<GameObject*>* m_gameObjects;
	public:
		void Update();

	};

}
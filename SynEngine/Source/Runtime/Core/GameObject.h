#pragma once

#include "Core.h"
#include <vector>
#include "Component.h"
#include "Scene.h"
#include "../Components/Transform.h"
#include <string>
#include "../Components/MeshRenderer.h"

namespace Syn {

	class SYN_API GameObject {
	public:
		GameObject(const char* name);
		~GameObject();

	private:
		const char* m_name;
		std::vector<Component*>* m_components;
		Syn::Components::Transform* m_transform;

	public:
		inline Syn::Components::Transform& Transform() { return *m_transform; }

		void AddComponent(Component& component);

		void virtual Update() {}
	};

}
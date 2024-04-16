#pragma once

#include "Core.h"
#include "Component.h"
#include "Object.h"
#include "../Components/Transform.h"
#include <vector>

namespace Syn::Core {

	class SYN_API GameObject : public Syn::Core::Object {
	public:
		GameObject(std::string name);
		GameObject();
		~GameObject();

	private:
		std::string m_name;
		std::vector<Component*> m_components;
		Syn::Components::Transform* m_transform;

	public:
		inline Syn::Components::Transform& Transform() { return *m_transform; }

		void AddComponent(Component& component);

		void virtual Update() {}
	};

}
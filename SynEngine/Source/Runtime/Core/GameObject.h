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
		std::string name;
		std::vector<Component*> components;
		Syn::Components::Transform* transform;

	public:
		void Begin() override;
		void Update() override;

		void AddComponent(Component& component);

		inline Syn::Components::Transform& Transform() { return *transform; }
	};

}
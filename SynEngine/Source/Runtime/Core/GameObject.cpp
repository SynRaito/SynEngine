#include "GameObject.h"


Syn::Core::GameObject::GameObject(std::string name) : GameObject()
{
	m_name = name;
}

Syn::Core::GameObject::GameObject()
{
	m_transform = new Syn::Components::Transform;
}

Syn::Core::GameObject::~GameObject()
{
	for (int i = 0; i < m_components.size(); ++i) {
		delete m_components[i];
	}
	delete m_transform;
}

void Syn::Core::GameObject::AddComponent(Syn::Component& component)
{
	m_components.push_back(&component);
}
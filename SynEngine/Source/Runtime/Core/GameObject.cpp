#include "GameObject.h"


Syn::GameObject::GameObject(const char* name)
{
	m_components = new std::vector<Component*>();
	m_transform = new Syn::Components::Transform;
	m_name = name;
}

Syn::GameObject::~GameObject()
{
	for (int i = 0; i < m_components->size(); ++i) {
		delete (*m_components)[i];
	}
	delete m_transform;
	delete m_name;
	delete m_components;
}

void Syn::GameObject::AddComponent(Syn::Component &component)
{
	m_components->push_back(&component);
}

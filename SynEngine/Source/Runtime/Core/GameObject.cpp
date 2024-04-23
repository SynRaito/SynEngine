#include "GameObject.h"


Syn::Core::GameObject::GameObject(std::string name) : GameObject()
{
	name = name;
}

Syn::Core::GameObject::GameObject()
{
	transform = new Syn::Components::Transform;
}

Syn::Core::GameObject::~GameObject()
{
	for (int i = 0; i < components.size(); ++i) {
		delete components[i];
	}
	delete transform;
}

void Syn::Core::GameObject::Begin()
{
	Object::Begin();
}

void Syn::Core::GameObject::Update()
{
}

void Syn::Core::GameObject::AddComponent(Syn::Component& component)
{
	components.push_back(&component);
}
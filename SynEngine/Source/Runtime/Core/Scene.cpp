#include "Scene.h"

Syn::Core::Scene::Scene()
{
	m_gameObjects = new std::vector<GameObject*>();
}

Syn::Core::Scene::~Scene()
{
	delete m_gameObjects;
}

void Syn::Core::Scene::Update(float deltaTime)
{
	for (Syn::Core::GameObject* gameObject : *m_gameObjects) {
		gameObject->Update(deltaTime);
	}
}

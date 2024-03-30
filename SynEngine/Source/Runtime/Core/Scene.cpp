#include "Scene.h"

Syn::Scene::Scene()
{
	m_gameObjects = new std::vector<GameObject*>();
}

Syn::Scene::~Scene()
{
	delete m_gameObjects;
}

void Syn::Scene::Update()
{
	for (GameObject* gameObject : *m_gameObjects) {
		gameObject->Update();
	}
}

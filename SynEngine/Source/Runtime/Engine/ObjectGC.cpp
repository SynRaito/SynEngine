#include "ObjectGC.h"

void Syn::Engine::ObjectGC::AddObject(IGarbageCollectable& obj)
{
	objects.push_back(&obj);
}

void Syn::Engine::ObjectGC::VisitObjects()
{
	for (int i = objects.size() - 1; i >= 0; --i) {
		if (objects[i]->IsCollectable() == true) {
			objects.erase(objects.begin() + i);
		}
	}
}

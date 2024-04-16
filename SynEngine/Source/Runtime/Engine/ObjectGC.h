#pragma once

#include "../Core/Core.h"
#include <vector>

class GameInstance;

namespace Syn::Engine {
	class SYN_API IGarbageCollectable {
		friend class ObjectGC;
		virtual bool IsCollectable() = 0;
	};
}

namespace Syn::Engine {

	class SYN_API ObjectGC {
	private:
		std::vector<IGarbageCollectable*> objects;


	public:

		void AddObject(IGarbageCollectable& obj);
		void VisitObjects();
	};
}
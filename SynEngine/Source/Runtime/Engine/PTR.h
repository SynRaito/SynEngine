#pragma once

#include "../Core/Core.h"
#include "../Engine/ObjectGC.h"
#include "ObjectGC.h"
#include <memory>

namespace Syn
{
	namespace Core
	{
		class GameInstance;
	}
}

namespace Syn::Engine {
	template<class T>
	class SYN_API PTR : public IGarbageCollectable {
		friend class Syn::Core::GameInstance;

	private:
		std::shared_ptr<T> rawPtr;
		bool* isValid = nullptr;

		void* operator new(size_t size){
			void *p = ::operator new(size); 
			return p;
		}
		void operator delete(void*p){
			free(p);
		}

	public:
		PTR()
		{
			if (rawPtr.use_count() == 0)
			{
				rawPtr = std::make_shared<T>();
				isValid = new bool;
				*isValid = true;
			}
		}

		~PTR() {
			if (rawPtr.use_count() == 2) {
				*isValid = false;
			}
		}

		void Destroy() {
			rawPtr.reset();
			*isValid = false;
		}

		bool IsValid() {
			return isValid;
		}

		T& Get() {
			return rawPtr.get();
		}

		bool IsCollectable() override
		{
			if (rawPtr.use_count() == 1) {
				return true;
			}
			return false;
		}
	};
}

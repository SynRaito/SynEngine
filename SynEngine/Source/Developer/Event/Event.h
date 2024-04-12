#pragma once

#include "../../Runtime/Core/Core.h"
#include <vector>
#include <functional>
#include <iostream>
#include "../../Runtime/Core/Object.h"
#include "../../Runtime/Engine/PTR.h"

namespace Syn {

	template<typename ... T>
	class SYN_API Event
	{
	private:
		std::vector<void(*)(T ...)> m_functionReferences;

	public:
		inline size_t RefCount() {
			return m_functionReferences.size();
		}

		inline void Register(void(*ref)(T ...)) {
			m_functionReferences.push_back(ref);
		}

		inline void Trigger(T ... args) {
			for (auto ref : m_functionReferences) {
				ref(args ...);
			}
		}

		Event<T ...>& operator+(void(*ref)(T ...)) {
			Register(ref);

			return *this;
		}

		Event<T ...>& operator+=(void(*ref)(T ...)) {
			Register(ref);

			return *this;
		}
	};

	template<typename ... T>
	class SYN_API LinkedEvent
	{
		template<typename ... T>
		class SYN_API LinkedEventClass {
		public:
			std::weak_ptr<Syn::Core::Object> ObjRef;
			std::function<void(T...)> FuncRef;
		};

	private:
		std::vector<LinkedEventClass<T...>> functionReferences;

	public:
		inline size_t RefCount() {
			return functionReferences.size();
		}

		inline void Register(Syn::Engine::PTR<Syn::Core::Object> Obj, std::function<void(T...)> Func) {
			LinkedEventClass<T...> LinkedEventClassObj;
			LinkedEventClassObj.ObjRef = Obj;
			LinkedEventClassObj.FuncRef = Func;

			functionReferences.push_back(LinkedEventClassObj);
		}

		inline void Trigger(T ... args) {
			for (auto &Ref : functionReferences) {
				if (!Ref.ObjRef.expired()) {
					Ref.FuncRef(args...);
				}
			}
		}

		LinkedEvent<T ...>& operator+(LinkedEventClass<T ...> ClassObj) {
			Register(ClassObj->ObjRef, ClassObj->FuncRef);
			return *this;
		}

		LinkedEvent<T ...>& operator+=(LinkedEventClass<T ...> ClassObj) {
			Register(ClassObj->ObjRef, ClassObj->FuncRef);
			return *this;
		}
	};
}
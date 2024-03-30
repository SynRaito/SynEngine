#pragma once

#include "../../Runtime/Core/Core.h"
#include <vector>
#include <functional>
#include <iostream>

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

	template<class LinkedClass, typename ... T>
	class SYN_API LinkedEvent
	{
		template<class LinkedClass, typename LinkedFunc>
		class SYN_API LinkedEventClass {
		public:
			LinkedClass* ObjRef;
			LinkedFunc* FuncRef;
		};

	private:
		std::vector<LinkedEventClass<LinkedClass, void(LinkedClass::*)(T ...)>> functionReferences;

	public:
		inline size_t RefCount() {
			return functionReferences.size();
		}

		inline void Register(LinkedClass& Obj, void(LinkedClass::* Ref)(T ...)) {
			LinkedEventClass<LinkedClass, void(LinkedClass::*)(T ...)> LinkedEventClassObj;
			LinkedEventClassObj.ObjRef = &Obj;
			LinkedEventClassObj.FuncRef = &Ref;

			functionReferences.push_back(LinkedEventClassObj);
		}

		inline void Trigger(T ... args) {
			for (auto &Ref : functionReferences) {
				if (Ref.ObjRef != nullptr && Ref.FuncRef != nullptr) {
					//std::invoke(*Ref.FuncRef, *Ref.ObjRef);
					((*Ref.ObjRef).*(*Ref.FuncRef))(args...);
				}
			}
		}

		LinkedEvent<LinkedClass, T ...>& operator+(LinkedEventClass<LinkedClass, void(LinkedClass::*)(T ...)> ClassObj) {
			Register(ClassObj->ObjRef, ClassObj->FuncRef);
			return *this;
		}

		LinkedEvent<LinkedClass, T ...>& operator+=(LinkedEventClass<LinkedClass, void(LinkedClass::*)(T ...)> ClassObj) {
			Register(ClassObj->ObjRef, ClassObj->FuncRef);
			return *this;
		}
	};
}
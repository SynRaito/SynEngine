#pragma once

#include "../../Runtime/Core/Core.h"
#include <vector>
#include <algorithm>
#include <functional>
#include "../../Runtime/Core/Object.h"
#include "../../Runtime/Engine/PTR.h"

namespace Syn {

	template<typename ... T>
	class SYN_API Event
	{
	private:
		std::vector<void(*)(T ...)> functionReferences;

	public:
		inline size_t RefCount() {
			return functionReferences.size();
		}

		inline void Register(void(*ref)(T ...)) {
			functionReferences.push_back(ref);
		}
		
		inline void Unregister(void(*ref)(T ...)) {
			auto found = std::find(functionReferences.begin(), functionReferences.end(), ref);
			if (found != functionReferences.end()) {
				functionReferences.erase(found);
			}
		}

		inline void Trigger(T ... args) {
			for (auto ref : functionReferences) {
				ref(args ...);
			}
		}

		Event<T ...>& operator+(void(*ref)(T ...)) {
			Register(ref);

			return *this;
		}
		
		Event<T ...>& operator-(void(*ref)(T ...)) {
			Unregister(ref);

			return *this;
		}

		Event<T ...>& operator+=(void(*ref)(T ...)) {
			Register(ref);

			return *this;
		}
		
		Event<T ...>& operator-=(void(*ref)(T ...)) {
			Unregister(ref);

			return *this;
		}
	};

	/***
	 * T = Potential multiple parameters
	**/
	template<typename ... T>
	class SYN_API LinkedEvent
	{
		template<typename ... T>
		class SYN_API LinkedEventClass {
		public:
			Syn::Engine::PTR<Syn::Core::Object> ObjRef;
			std::function<void(T...)> FuncRef;
		};

	private:
		std::vector<LinkedEventClass<T...>> functionReferences;

	public:
		inline size_t RefCount() {
			return functionReferences.size();
		}

		/**
		 * Example Usage : Register(obj, PTR<T>::obj.Bind(&Syn::Core::TestFunc));
		 * obj must be derived from Object
		 **/
		inline void Register(Syn::Engine::PTR<Syn::Core::Object> Obj, std::function<void(T...)> Func) {
			LinkedEventClass<T...> LinkedEventClassObj;
			LinkedEventClassObj.ObjRef = Obj;
			LinkedEventClassObj.FuncRef = Func;

			functionReferences.push_back(LinkedEventClassObj);
		}

		inline void Unregister(Syn::Engine::PTR<Syn::Core::Object> Obj, std::function<void(T...)> Func) {
			auto found = std::find_if(functionReferences.begin(), functionReferences.end(), [&](LinkedEventClass<T...> const& lec) {
				return lec.ObjRef == Obj && Func.target_type() == lec.FuncRef.target_type();
			});
			if (found != functionReferences.end()) {
				functionReferences.erase(found);
			}
		}

		inline void Trigger(T ... args) {
			for (auto &Ref : functionReferences) {
				if (Ref.ObjRef.IsValid()) {
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
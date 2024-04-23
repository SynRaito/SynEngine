#pragma once

#include "../Core/Core.h"
#include "../Core/Component.h"
#include "../../Developer/Math/Vector4D.h"

namespace Syn::Components {

	class SYN_API Transform : Component {

	public:
		Transform() : position(), rotation(), scale() {}
		constexpr Transform(Syn::Math::Vector3D position, Syn::Math::Vector3D rotation, Syn::Math::Vector3D scale) : position(position), rotation(rotation), scale(scale) {}

	private:
		Syn::Math::Vector3D position;
		Syn::Math::Vector3D rotation;
		Syn::Math::Vector3D scale;

	public:
		inline constexpr Syn::Math::Vector3D Position() { return position; }
		inline void Position(Syn::Math::Vector3D vector) { position = vector; }
		inline constexpr Syn::Math::Vector3D Rotation() { return rotation; }
		inline void Rotation(Syn::Math::Vector3D vector) { rotation = vector; }
		inline constexpr Syn::Math::Vector3D Scale() { return scale; }
		inline void Scale(Syn::Math::Vector3D vector) { scale = vector; }

		void Translate(Syn::Math::Vector3D vector);
		void Rotate(Syn::Math::Vector3D vector);
	};
}
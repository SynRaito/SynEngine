#pragma once

#include "../Core/Core.h"
#include "../Core/Component.h"
#include "../../Developer/Math/Vector4D.h"

namespace Syn::Components {

	class SYN_API Transform : Component {

	public:
		Transform() : m_position(), m_rotation(), m_scale() {}
		constexpr Transform(Syn::Math::Vector3D position, Syn::Math::Vector3D rotation, Syn::Math::Vector3D scale) : m_position(position), m_rotation(rotation), m_scale(scale) {}

	private:
		Syn::Math::Vector3D m_position;
		Syn::Math::Vector3D m_rotation;
		Syn::Math::Vector3D m_scale;

	public:
		inline constexpr Syn::Math::Vector3D Position() { return m_position; }
		inline void Position(Syn::Math::Vector3D vector) { m_position = vector; }
		inline constexpr Syn::Math::Vector3D Rotation() { return m_rotation; }
		inline void Rotation(Syn::Math::Vector3D vector) { m_rotation = vector; }
		inline constexpr Syn::Math::Vector3D Scale() { return m_scale; }
		inline void Scale(Syn::Math::Vector3D vector) { m_scale = vector; }

		void Translate(Syn::Math::Vector3D vector);
		void Rotate(Syn::Math::Vector3D vector);
	};
}
#include "Transform.h"

void Syn::Components::Transform::Translate(Syn::Math::Vector3D vector)
{
	position += vector;
}
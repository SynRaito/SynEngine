#pragma once

#include "../Core/Core.h"
#include "../Core/Component.h"

namespace Syn::Components {

	class SYN_API MeshRenderer : Syn::Component {

	public:
		MeshRenderer();

		void Update() override;
	};

}
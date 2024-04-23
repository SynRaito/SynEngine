#pragma once

#include "Core.h"
#include "../Engine/ObjectGC.h"
#include <iostream>


namespace Syn::Core {

	class SYN_API Object {

	public:
		Object();

		void virtual Begin();
		void virtual Update(float deltaTime);

	};

}
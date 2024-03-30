#pragma once

#include "Core.h"

namespace Syn{

	class SYN_API Component {

	public:
		virtual void Initialize(){}
		virtual void Update(){}
	};
}
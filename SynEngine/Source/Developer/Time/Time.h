#pragma once

#include "../../Runtime/Core/Core.h"

namespace Syn {
	class SYN_API Time {
	private:
		double time;
		float deltaTime;
	
	public:
		double EvaluateDeltaTime();
		double DeltaTime() { return deltaTime; }
	};
}
#include "Time.h"
#include <glad.h>
#include <glfw3.h>

double Syn::Time::EvaluateDeltaTime()
{
	double currentTime = glfwGetTime();
	deltaTime = currentTime - time;
	time = currentTime;
	return deltaTime;
}
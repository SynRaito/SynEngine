#include "Window.h"
#include <iostream>

Syn::Core::Window::Window(int width, int height, const char* name) 
{
    glfwWindow = glfwCreateWindow(width, height, name, NULL, NULL);
}

GLFWwindow* Syn::Core::Window::GlfwWindow()
{
    return glfwWindow;
}

void Syn::Core::Window::Update(float deltaTime)
{
    glfwMakeContextCurrent(glfwWindow);

    if (glfwWindowShouldClose(glfwWindow))
    {
        glfwTerminate();

        return;
    }

    /* Render here */

    glClearColor(1, 1, 1, 1);

    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(glfwWindow);

    /* Poll for and process events */
    glfwPollEvents();
}

void Syn::Core::Window::Close()
{
    glfwSetWindowShouldClose(glfwWindow, true);
}

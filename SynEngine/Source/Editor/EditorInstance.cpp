#include "EditorInstance.h"

Syn::Editor::EditorInstance::~EditorInstance()
{
	for (int i = 0; i < m_windows.size(); ++i) {
		delete m_windows[i];
	}
}

void Syn::Editor::EditorInstance::CreateWindow(int width, int height, const char* name)
{
	Syn::Editor::Window* NewWindow = new Window(1000, 1000, name);

	m_windows.push_back(NewWindow);
}

void Syn::Editor::EditorInstance::RenderWindows()
{
	for (Syn::Editor::Window* window : m_windows) {
		window->Update();
	}
}

void Syn::Editor::EditorInstance::Render()
{
	RenderWindows();
}

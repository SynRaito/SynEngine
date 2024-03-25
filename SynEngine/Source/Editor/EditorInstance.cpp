#include "EditorInstance.h"

Syn::Editor::EditorInstance::~EditorInstance()
{
	for (int i = 0; i < Windows.size(); ++i) {
		delete Windows[i];
	}
}

void Syn::Editor::EditorInstance::CreateWindow(int width, int height, const char* name)
{
	Syn::Editor::Window* NewWindow = new Window(1000, 1000, name);

	Windows.push_back(NewWindow);
}

void Syn::Editor::EditorInstance::RenderWindows()
{
	for (Syn::Editor::Window* window : Windows) {
		window->Update();
	}
}

void Syn::Editor::EditorInstance::Render()
{
	RenderWindows();
}

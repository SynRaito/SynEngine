#pragma once

#ifdef SYN_PLATFORM_WINDOWS

extern Syn::Application* Syn::CreateApplication();

int main(int argc, char** argv) {
	printf("TEst");
	auto app = Syn::CreateApplication();
	app->Run();
	delete app;
}

#endif
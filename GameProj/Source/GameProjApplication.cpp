#include <Syn.h>

class GameProj : public Syn::Application {
public:
	GameProj() {

	}

	~GameProj() {

	}
};

Syn::Application* Syn::CreateApplication()
{
	return new GameProj;
}
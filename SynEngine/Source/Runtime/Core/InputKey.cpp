#include "InputKey.h"

Syn::Core::InputKey::InputKey(KeyCode KeyCode) : keyCode(KeyCode) , state(KeyState::None)
{
}

void Syn::Core::InputKey::SetState(KeyState KeyState)
{
	state = KeyState;
	if (KeyState == KeyState::Pressed) {
		OnPressed.Trigger();
	}
	else if (KeyState == KeyState::Released) {
		OnReleased.Trigger();
	}
}

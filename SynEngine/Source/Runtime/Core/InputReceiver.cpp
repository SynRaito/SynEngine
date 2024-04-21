#include "InputReceiver.h"
#include "Window.h"
#include <glad.h>
#include <glfw3.h>

Syn::Core::InputReceiver::InputReceiver()
{

	#pragma region Input Inserts

	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::A), InputKey(InputKey::KeyCode::A));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::B), InputKey(InputKey::KeyCode::B));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::C), InputKey(InputKey::KeyCode::C));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::D), InputKey(InputKey::KeyCode::D));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::E), InputKey(InputKey::KeyCode::E));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::F), InputKey(InputKey::KeyCode::F));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::G), InputKey(InputKey::KeyCode::G));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::H), InputKey(InputKey::KeyCode::H));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::I), InputKey(InputKey::KeyCode::I));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::J), InputKey(InputKey::KeyCode::J));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::K), InputKey(InputKey::KeyCode::K));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::L), InputKey(InputKey::KeyCode::L));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::M), InputKey(InputKey::KeyCode::M));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::N), InputKey(InputKey::KeyCode::N));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::O), InputKey(InputKey::KeyCode::O));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::P), InputKey(InputKey::KeyCode::P));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::Q), InputKey(InputKey::KeyCode::Q));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::R), InputKey(InputKey::KeyCode::R));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::S), InputKey(InputKey::KeyCode::S));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::T), InputKey(InputKey::KeyCode::T));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::U), InputKey(InputKey::KeyCode::U));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::V), InputKey(InputKey::KeyCode::V));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::W), InputKey(InputKey::KeyCode::W));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::X), InputKey(InputKey::KeyCode::X));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::Y), InputKey(InputKey::KeyCode::Y));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::Z), InputKey(InputKey::KeyCode::Z));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::ESCAPE), InputKey(InputKey::KeyCode::ESCAPE));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::ENTER), InputKey(InputKey::KeyCode::ENTER));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::TAB), InputKey(InputKey::KeyCode::TAB));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::BACKSPACE), InputKey(InputKey::KeyCode::BACKSPACE));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::INSERT), InputKey(InputKey::KeyCode::INSERT));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::DELETE), InputKey(InputKey::KeyCode::DELETE));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::RIGHT), InputKey(InputKey::KeyCode::RIGHT));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::LEFT), InputKey(InputKey::KeyCode::LEFT));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::DOWN), InputKey(InputKey::KeyCode::DOWN));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::UP), InputKey(InputKey::KeyCode::UP));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::PAGE_UP), InputKey(InputKey::KeyCode::PAGE_UP));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::PAGE_DOWN), InputKey(InputKey::KeyCode::PAGE_DOWN));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::HOME), InputKey(InputKey::KeyCode::HOME));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::END), InputKey(InputKey::KeyCode::END));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::CAPS_LOCK), InputKey(InputKey::KeyCode::CAPS_LOCK));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::SCROLL_LOCK), InputKey(InputKey::KeyCode::SCROLL_LOCK));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::NUM_LOCK), InputKey(InputKey::KeyCode::NUM_LOCK));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::PRINT_SCREEN), InputKey(InputKey::KeyCode::PRINT_SCREEN));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::F1), InputKey(InputKey::KeyCode::F1));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::F2), InputKey(InputKey::KeyCode::F2));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::F3), InputKey(InputKey::KeyCode::F3));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::F4), InputKey(InputKey::KeyCode::F4));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::F5), InputKey(InputKey::KeyCode::F5));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::F6), InputKey(InputKey::KeyCode::F6));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::F7), InputKey(InputKey::KeyCode::F7));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::F8), InputKey(InputKey::KeyCode::F8));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::F9), InputKey(InputKey::KeyCode::F9));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::F10), InputKey(InputKey::KeyCode::F10));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::F11), InputKey(InputKey::KeyCode::F11));
	InputKeys.emplace(static_cast<int>(InputKey::KeyCode::F12), InputKey(InputKey::KeyCode::F12));

	#pragma endregion

}

void Syn::Core::InputReceiver::ProcessInputs(Window* window)
{
	if(window == nullptr)
		return;

	for(std::pair<const int , InputKey> Key : InputKeys)
	{
		HandleInputState(*window, Key);
	}
}

void Syn::Core::InputReceiver::HandleInputState(Window &window, std::pair<const int , InputKey> key)
{
	if (glfwGetKey(window.GlfwWindow(), key.first) == static_cast<int>(InputKey::KeyState::Pressed)) {
		if(key.second.State() == InputKey::KeyState::None || key.second.State() == InputKey::KeyState::Released)
		{
			InputKeys[key.first].SetState(InputKey::KeyState::Pressed);
		}
		else if(key.second.State() == InputKey::KeyState::Pressed)
		{
			InputKeys[key.first].SetState(InputKey::KeyState::Hold);
		}
	}
	else {
		if(key.second.State() == InputKey::KeyState::Pressed || key.second.State() == InputKey::KeyState::Hold)
		{
			InputKeys[key.first].SetState(InputKey::KeyState::Released);
		}
		else if(key.second.State() == InputKey::KeyState::Released)
		{
			InputKeys[key.first].SetState(InputKey::KeyState::None);
		}
	}
}


void Syn::Core::InputReceiver::RegisterEvent(InputKey::KeyCode keyCode, InputKey::KeyState keyState, Engine::PTR<Object> obj, std::function<void()> func)
{
	if(keyState == InputKey::KeyState::Pressed)
	{
		InputKeys[static_cast<int>(keyCode)].OnPressed.Register(obj, func);
	}
	else if(keyState == InputKey::KeyState::Released)
	{
		InputKeys[static_cast<int>(keyCode)].OnReleased.Register(obj, func);
	}
}

void Syn::Core::InputReceiver::UnregisterEvent(InputKey::KeyCode keyCode, InputKey::KeyState keyState, Engine::PTR<Object> obj, std::function<void()> func)
{
	if (keyState == InputKey::KeyState::Pressed)
	{
		InputKeys[static_cast<int>(keyCode)].OnPressed.Unregister(obj, func);
	}
	else if (keyState == InputKey::KeyState::Released)
	{
		InputKeys[static_cast<int>(keyCode)].OnReleased.Unregister(obj, func);
	}
}
#include "Input.h"

bool Input::KeyState(int in_keyValue)
{
	return GetAsyncKeyState(in_keyValue);
}

#include "Input.h"

Input::Input()
{
}

Input::~Input()
{
}


void Input::setKeyDown(int key)
{
	keys[key] = true;
}

void Input::setKeyUp(int key)
{
	keys[key] = false;
}
bool Input::isKeyDown(int key)
{
	return keys[key];
}

int Input::getMouseX()
{
	return mouse.x;
}

int Input::getMouseY()
{
	return mouse.y;
}

void Input::setMousePosition(int lx, int ly)
{
	setMouseX(lx);
	setMouseY(ly);
}

void Input::setMouseX(int lx)
{
	mouse.x = lx;
}

void Input::setMouseY(int ly)
{
	mouse.y = ly;
}

void Input::setMouseLeftDown(bool button)
{
	mouse.left = button;
}

void Input::setMouseLeftUp(bool button)
{
	mouse.left = button;
}

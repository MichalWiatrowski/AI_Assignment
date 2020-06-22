#pragma once
//Input manager class supplied by Paul Robertson in games programming module
class Input

{
private:
	struct Mouse
	{
		int x, y;
		bool left;
	};

	bool keys[256]{ false };
	Mouse mouse;

public:
	Input();
	~Input();
	void setKeyDown(int key);
	void setKeyUp(int key);
	bool isKeyDown(int key);

	void setMouseX(int lx);
	void setMouseY(int ly);
	void setMousePosition(int lx, int ly);
	void setMouseLeftDown(bool button);
	void setMouseLeftUp(bool button);


	int getMouseX();
	int getMouseY();


};
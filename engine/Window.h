#pragma once

#ifndef _WINDOW_
#define _WINDOW_
#include "../pch.h"
#include "../utils/Error.h"

//1
//10
//100
enum WindowFlags {
	INVISBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4
};

class Window
{
private:
	SDL_Window* _window;
	int _screenWidth, _screenHeight;
public:
	Window();
	~Window();
	void swapBuffer();
	int getScreenWidth() { _screenWidth; };
	int getScreenHeight() { _screenHeight; };
	int create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);
};

#include "Window.inl"
#endif

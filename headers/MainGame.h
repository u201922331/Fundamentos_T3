#pragma once
#ifndef _MAINGAME_
#define _MAINGAME_

#include "pch.h"

#include "utils/GLS_Program.h"
#include "engine/Window.h"
#include "world/Camera2D.h"
#include "resources/SpriteBacth.h"
#include "engine/InputManager.h"
#include "engine/Level.h"
#include "world/Player.h"
#include "world/Human.h"
#include "world/Zombie.h"

#include "resources/ImageLoader.h"
#include "resources/ResourceManager.h"
#include "engine/PapuEngine.h"

enum class GameState
{
	PLAY, EXIT
};


class MainGame
{
private:
	int _witdh;
	int _height;
	float _time;
	Window _window;
	void init();
	void procesInput();
	GLS_Program _program;
	Camera2D _camera;
	SpriteBacth _spriteBacth;
	InputManager _inputManager;
	vector<Level*> _levels;
	vector<Human*> _humans;
	vector<Zombie*> _zombies;
	Player* _player;
	int _currenLevel;
	void initLevel();

public:
	MainGame();
	~MainGame();
	GameState _gameState;
	void initShaders();
	void run();
	void draw();
	void update();
};

#include "MainGame.inl"
#endif

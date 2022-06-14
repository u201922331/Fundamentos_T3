#pragma once

#ifndef _PLAYER_
#define _PLAYER_

#include "../pch.h"
#include "Human.h"
#include "../engine/InputManager.h"

class Player : public Human
{
private:
	float _speed;
	InputManager* _inputManager;
public:
	void init(float speed, glm::vec2 position, InputManager* InputManager);
	void update(const std::vector<std::string>& levelData);
	Player();
	~Player();
};

#include "Player.inl"
#endif

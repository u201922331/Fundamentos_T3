#pragma once

#ifndef _ZOMBIE_
#define _ZOMBIE_

#include "../pch.h"
#include "Agent.h"

class Zombie : public Agent
{
public:
	Zombie();
	~Zombie();

	void init(float speed, glm::vec2 position);
	void update(const std::vector<std::string>& levelData);
};

#include "Zombie.inl"
#endif

#pragma once

#ifndef _AGENT_
#define _AGENT_

#include "../pch.h"
#include "../resources/SpriteBacth.h"
#include "../resources/ResourceManager.h"
#include "../engine/Level.h"
#include "../models/GLTexture.h"

const float AGENT_WITDH = 60.f;
const float AGENT_RADIUS = AGENT_WITDH / 2.0f;

class Agent
{
protected:
	glm::vec2 _position;
	float _speed;
	Color _color;
	void checkTilePosition(const std::vector<std::string>& levelData,
		std::vector<glm::vec2>& collideWithTIlePosition, float x, float y);
	void collideWithTile(glm::vec2 tilePos);
public:
	Agent();
	glm::vec2 getPosition() const { return _position; };
	virtual void update(const std::vector<std::string>& levelData) = 0;
	void draw(SpriteBacth& spritebatch);
	bool collideWithLevel(const std::vector<std::string>& levelData);
	~Agent();
};

#include "Agent.inl"
#endif

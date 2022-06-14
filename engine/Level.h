#pragma once

#ifndef _LEVEL_
#define _LEVEL_

#include "../pch.h"
#include "../resources/SpriteBacth.h"

#include "../resources/ResourceManager.h"
#include "../utils/Error.h"

const int TILE_WIDTH = 64;
class Level
{

private:
	vector<std::string> _levelData;
	int _numHumans;
	void parseLevel();
public:
	glm::vec2 _playerPosition;
	std::vector<glm::vec2> _zombiesPosition;
	glm::vec2 getPlayerPosition() const {
		return _playerPosition;
	};
	std::vector<glm::vec2> getZombiesPosition()const {
		return _zombiesPosition;
	};

	vector<std::string> getLevelData() const {
		return _levelData;
	}

	int getHeight() const {
		return _levelData[0].size();
	}

	int getWidth() const {
		return _levelData[0].size();
	}

	int getNumHums()const {
		return _numHumans;
	}

	Level(const std::string& fileName);
	void draw();
	SpriteBacth _spriteBatch;
	~Level();
};

#include "Level.inl"
#endif

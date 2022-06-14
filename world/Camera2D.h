#pragma once

#ifndef _CAMERA2D_
#define _CAMERA2D_

#include "../pch.h"

class Camera2D
{
private:
	glm::vec2 _position;
	float _scale;
	bool _needsMatrixUpdate;
	glm::mat4 _cameraMatrix;
	glm::mat4 _orthoMatrix;
	int _screenWidth;
	int _screenHeight;
public:
	Camera2D();
	~Camera2D();
	glm::vec2 convertScreenToWorl(glm::vec2 screenScoords);
	void init(int screenWidth, int screenHeight);

	void update();

	void setPosition(const glm::vec2& newPosition) {
		_position = newPosition;
		_needsMatrixUpdate = true;
	}
	void setScale(float newScale) {
		_scale = newScale;
		_needsMatrixUpdate = true;
	}

	glm::mat4 getCameraMatrix() {
		return _cameraMatrix;
	}

	glm::vec2 getPosition() {
		return _position;
	}

	float getScale() {
		return _scale;
	}
};

#include "Camera2D.inl"
#endif

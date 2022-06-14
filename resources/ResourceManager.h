#pragma once

#ifndef _RESOURCEMANAGER_
#define _RESOURCEMANAGER_

#include "../pch.h"
#include "../models/GLTexture.h"
#include "TextureCache.h"

class ResourceManager
{
private:
	static TextureCache _textureCache;
public:
	static GLTexture getTexture(std::string texturePath);
};

#include "ResourceManager.inl"
#endif

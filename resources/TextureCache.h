#pragma once

#ifndef _TEXTURECACHE_
#define _TEXTURECACHE_

#include "../pch.h"
#include "ImageLoader.h"
#include "../models/GLTexture.h"

class TextureCache
{
	std::map<std::string, GLTexture> _textureMap;
public:
	TextureCache();
	~TextureCache();
	GLTexture getTexture(std::string texturePath);
};

#include "TextureCache.inl"
#endif

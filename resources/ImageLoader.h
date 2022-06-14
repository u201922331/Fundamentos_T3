#pragma once

#ifndef _IMAGELOADER_
#define _IMAGELOADER_

#include "../pch.h"
#include "../models/GLTexture.h"
#include "../utils/picoPNG.h"
#include "../utils/Error.h"
#include "../engine/IOManager.h"

class ImageLoader
{
public:
	static GLTexture loadPNG(std::string filePath);
};

#include "ImageLoader.inl"
#endif

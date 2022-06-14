#pragma once

#ifndef _IOMANAGER_
#define _IOMANAGER_

#include "../pch.h"

class IOManager
{
public:
	static bool readFileToBuffer(std::string filePath,
		std::vector<unsigned char>& buffer);
};

#include "IOManager.inl"
#endif

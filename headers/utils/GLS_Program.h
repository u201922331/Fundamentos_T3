#pragma once

#ifndef _SHADERPROGRAM_
#define _SHADERPROGRAM_

#include "../pch.h"
#include "Error.h"
using namespace std;

class GLS_Program
{
private:
	GLuint _programID;
	GLuint _fragmentShaderID;
	GLuint _vertexShaderID;

	void compileShader(const string& shaderPath, GLuint id);

public:
	GLS_Program();
	~GLS_Program();
	int _numAtribute;
	void addAtribute(const string atributeName);
	void use();
	void unuse();
	void compileShaders(const string& vertexShaderFilePath,
		const string& fragmentShaderFilePath);

	void linkShader();

	GLuint getUniformLocation(const string& name);

};

#include "GLS_Program.inl"
#endif

#pragma once

#ifndef _SPRITEBATCH_
#define _SPRITEBATCH_

#include "../pch.h"
#include "../models/Vertex.h"

enum class GlyphSortType {
	NONE,
	FRONT_TO_BACK,
	BACK_TO_FRONT,
	TEXTURE
};

struct Glyph {
	GLuint texture;
	float depth;
	Vertex topLeft;
	Vertex bottomLeft;
	Vertex topRight;
	Vertex bottomRight;
};

class RenderBatch {
public:
	RenderBatch(GLuint offset, GLuint numVertixex, GLuint texture);

	GLuint _offset;
	GLuint _numVertixes;
	GLuint _texture;
};

class SpriteBacth
{
private:
	GLuint _vbo;
	//
	GLuint _vao;
	std::vector<Glyph*> _glyphs;
	std::vector<RenderBatch> _renderBacthes;
	void createVertexArray();
	void sortGlyph();
	GlyphSortType _sortType;
	void createRenderBatches();

public:
	SpriteBacth();
	~SpriteBacth();
	void init();
	void begin(GlyphSortType sortType = GlyphSortType::TEXTURE);
	void end();
	void draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, float depth, const Color& color);
	void renderBatch();

	static bool compareFrontToBack(Glyph* a, Glyph* b);

	static bool compareBackToFront(Glyph* a, Glyph* b);

	static bool compareTexture(Glyph* a, Glyph* b);
};

#include "SpriteBacth.inl"
#endif

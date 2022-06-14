Agent::Agent()
{

}

void Agent::draw(SpriteBacth& spritebatch) {
	static int textureID = ResourceManager::getTexture("assets/textures/circle.png").id;
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	glm::vec4 destRect(_position.x, _position.y, AGENT_WITDH, AGENT_WITDH);
	spritebatch.draw(destRect, uvRect, textureID, 0.0f, _color);
}

bool Agent::collideWithLevel(const std::vector<std::string>& levelData) {
	std::vector<glm::vec2> collideTilePosition;


	checkTilePosition(levelData, collideTilePosition, _position.x, _position.y);

	checkTilePosition(levelData, collideTilePosition, _position.x + AGENT_WITDH, _position.y);
	checkTilePosition(levelData, collideTilePosition, _position.x, _position.y + AGENT_WITDH);
	checkTilePosition(levelData, collideTilePosition, _position.x + AGENT_WITDH, _position.y + AGENT_WITDH);

	if (collideTilePosition.size() == 0) return false;

	for (size_t i = 0; i < collideTilePosition.size(); i++)
	{
		collideWithTile(collideTilePosition[i]);
	}

	return true;
}

void Agent::checkTilePosition(const std::vector<std::string>& levelData, std::vector<glm::vec2>& collideTilePosition, float x, float y) {
	glm::vec2 cornesPos = glm::vec2(floor(x / (float)TILE_WIDTH),
		floor(y / (float)TILE_WIDTH));

	if (cornesPos.x < 0 || cornesPos.x >= levelData[0].size() || cornesPos.y < 0 || cornesPos.y >= levelData.size()) {
		return;
	}
	if (levelData[cornesPos.y][cornesPos.x] != '.') {
		collideTilePosition.push_back(cornesPos * (float)TILE_WIDTH + glm::vec2((float)TILE_WIDTH / 2.0f));
	}
}

void Agent::collideWithTile(glm::vec2 tilePos) {

	const float TILE_RADIUS = (float)TILE_WIDTH / 2.0f;
	const float MIN_DISTANCE = AGENT_RADIUS + TILE_RADIUS;

	glm::vec2 centerPosition = _position + glm::vec2(AGENT_RADIUS);
	glm::vec2 distVec = centerPosition - tilePos;
	float xdepth = MIN_DISTANCE - abs(distVec.x);
	float ydepth = MIN_DISTANCE - abs(distVec.y);

	if (xdepth > 0 || ydepth > 0) {
		if (std::max(xdepth, 0.0f) < std::max(ydepth, 0.0f)) {
			if (distVec.x < 0) {
				_position.x -= xdepth;
			}
			else {
				_position.x += xdepth;
			}
		}
		else {
			if (distVec.y < 0) {
				_position.y -= ydepth;
			}
			else {
				_position.y += ydepth;
			}
		}
	}
}

Agent::~Agent()
{
}
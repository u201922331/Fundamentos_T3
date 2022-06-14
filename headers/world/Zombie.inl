Zombie::Zombie()
{
}


Zombie::~Zombie()
{
}

void Zombie::init(float speed, glm::vec2 position) {
	_speed = speed;
	_color.set(255, 234, 0, 255); // MAIN
	//_color.set(0, 94, 47, 255); // BRANCH
	_position = position;
	/*static std::mt19937 randomEngine(time(nullptr));
	static std::uniform_real_distribution<float>randDir(-1.0f, 1.0f);

	_direction = glm::vec2(randDir(randomEngine), randDir(randomEngine));
	if (_direction.length() == 0) {
		_direction = glm::vec2(1.0f, 1.0f);
	}
	_direction = glm::vec2(_direction);*/
}

void Zombie::update(const std::vector<std::string>& levelData) {
	/*static std::mt19937 randomEngine(time(nullptr));
	_position = _direction * _speed;*/
}
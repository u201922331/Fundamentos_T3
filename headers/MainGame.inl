void MainGame::run() {
	init();
	update();
}

void MainGame::init() {
	Papu::init();
	_window.create("Engine", _witdh, _height, 0);
	glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
	initLevel();
	initShaders();
}

void MainGame::initLevel() {
	_levels.push_back(new Level("assets/layouts/level1.txt"));
	_player = new Player();
	_player->init(5.0f, _levels[_currenLevel]->getPlayerPosition(), &_inputManager);
	_currenLevel = 0;
	_spriteBacth.init();

	std::mt19937 randomEngine(time(nullptr));
	std::uniform_int_distribution<int>randPosX(1, 200);
	std::uniform_int_distribution<int>randPosY(1, 300);
	for (int i = 0; i < _levels[_currenLevel]->getNumHums(); i++) {
		_humans.push_back(new Human());
		glm::vec2 pos(randPosX(randomEngine) * TILE_WIDTH, randPosY(randomEngine) * TILE_WIDTH);
		_humans.back()->init(1.0f, pos);
	}
	for (int i = 0; i < _levels[_currenLevel]->_zombiesPosition.size(); i++) {
		_zombies.push_back(new Zombie());
		glm::vec2 pos(
			_levels[_currenLevel]->getZombiesPosition()[i].x * TILE_WIDTH,
			_levels[_currenLevel]->getZombiesPosition()[i].y * TILE_WIDTH
		);
		_zombies.back()->init(1.5f, pos);
	}
}

void MainGame::initShaders() {
	_program.compileShaders("assets/shaders/color.vert", "assets/shaders/color.frag");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("vertexUV");
	_program.linkShader();
}


void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();

	glActiveTexture(GL_TEXTURE0);

	GLuint pLocation =
		_program.getUniformLocation("P");

	glm::mat4 cameraMatrix = _camera.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1,GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);

	_spriteBacth.begin();
	_levels[_currenLevel]->draw();
	_player->draw(_spriteBacth);
	for (size_t i = 0; i < _humans.size(); i++) {
		_humans[i]->draw(_spriteBacth);
	}
	for (size_t i = 0; i < _zombies.size(); i++) {
		_zombies[i]->draw(_spriteBacth);
	}
	_spriteBacth.end();
	_spriteBacth.renderBatch();

	glBindTexture(GL_TEXTURE_2D, 0);

	_program.unuse();
	_window.swapBuffer();
}

void MainGame::procesInput() {
	SDL_Event event;
	const float CAMERA_SPEED = 20.0f;
	const float SCALE_SPEED = 0.1f;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				_inputManager.setMouseCoords(event.motion.x,event.motion.y);
			break;
			case  SDL_KEYUP:
				_inputManager.releaseKey(event.key.keysym.sym);
				break;
			case  SDL_KEYDOWN:
				_inputManager.pressKey(event.key.keysym.sym);
				break;
			case SDL_MOUSEBUTTONDOWN:
				_inputManager.pressKey(event.button.button);
				break;
			case SDL_MOUSEBUTTONUP:
				_inputManager.releaseKey(event.button.button);
				break;
		}

		/*if (_inputManager.isKeyPressed(SDLK_w)) {
			_camera.setPosition(_camera.getPosition() + glm::vec2(0.0, CAMERA_SPEED));
		}
		if (_inputManager.isKeyPressed(SDLK_s)) {
			_camera.setPosition(_camera.getPosition() + glm::vec2(0.0, -CAMERA_SPEED));
		}
		if (_inputManager.isKeyPressed(SDLK_a)) {
			_camera.setPosition(_camera.getPosition() + glm::vec2(-CAMERA_SPEED, 0.0));
		}
		if (_inputManager.isKeyPressed(SDLK_d)) {
			_camera.setPosition(_camera.getPosition() + glm::vec2(CAMERA_SPEED, 0.0));
		}*/
		if (_inputManager.isKeyPressed(SDLK_q)) {
			_camera.setScale(_camera.getScale() + SCALE_SPEED);
		}
		if (_inputManager.isKeyPressed(SDLK_e)) {
			_camera.setScale(_camera.getScale() - SCALE_SPEED);
		}
		if (_inputManager.isKeyPressed(SDL_BUTTON_LEFT)) {
			
		}
	}
}

void MainGame::update() {

	while (_gameState != GameState::EXIT) {
		procesInput();
		draw();
		_camera.update();
		_player->update(_levels[_currenLevel]->getLevelData());
		_camera.setPosition(_player->getPosition());

		for (size_t i = 0; i < _humans.size(); i++)
		{
			_humans[i]->update(_levels[_currenLevel]->getLevelData());
		}
		
	}
}


MainGame::MainGame(): 
	_witdh(800),
	_height(600),
	_gameState(GameState::PLAY),
	_time(0)
{
	_camera.init(_witdh, _height);
}


MainGame::~MainGame()
{
}

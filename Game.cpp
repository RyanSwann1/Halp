#include "Game.h"
#include "InputManager.h"
#include "Player.h"
#include "TextureManager.h"
#include "PlayState.h"
#include <SDL_image.h>


#include <assert.h>

Game * Game::sm_instance = nullptr;

Game::Game()
{
	m_running = false;
}

Game::~Game()
{
}

Game * Game::instance()
{
	if (sm_instance == nullptr) {
		sm_instance = new Game();
	}
	return sm_instance;
}


void Game::handleEvents()
{
	InputManager::instance()->update();
}

bool Game::init(const char* title, int w, int h)
{
	//Init SDL Video
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG); //Initialize images
	//int flags = IMG_INIT_PNG;

	//Create the window
	m_window = std::unique_ptr<SDL_Window, SDLDeleter>(SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN), SDLDeleter());
	assert(m_window != nullptr);
	//Create the renderer
	m_renderer = std::unique_ptr<SDL_Renderer, SDLDeleter>(SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_PRESENTVSYNC), SDLDeleter());
	assert(m_renderer != nullptr);
	//Get the window surface
	m_windowSurface = std::unique_ptr<SDL_Surface, SDLDeleter>(SDL_GetWindowSurface(m_window.get()), SDLDeleter());
	assert(m_windowSurface != nullptr);

	//Set up states
	m_gameStateMachine.startState(new PlayState());

	//Load textures
	TextureManager::instance()->load("Player", "PlayerShip.PNG");

	m_running = true; //Game is running
	m_sizeWidth = w;
	m_sizeHeight = h;

	return true; 	//If reached, init succesful
}

void Game::update()
{

	m_gameStateMachine.update();
	//if (InputManager::instance()->isKeyDown(SDL_SCANCODE_D)) {
	//	printf("D\n");
	//}
}

void Game::addGameObjects()
{
	m_gameObjects.push_back(new Player());
}

void Game::render()
{
	SDL_RenderClear(m_renderer.get()); //Clear renderer
	//SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 0); //Have background as black
	//Render game objects
	m_gameStateMachine.draw();

	//SDL_Rect srcRect;
	//SDL_Rect destRect;
	//srcRect.h = destRect.h = 50;
	//srcRect.w = destRect.w = 50;
	//srcRect.x = 0;
	//srcRect.y = 0;
	//destRect.x = 100;
	//destRect.y = 100;

	//SDL_RenderCopy(m_renderer.get(), TextureManager::instance()->getPlayerTexture("Player"), &srcRect, &destRect);
	//Apply rendering
	SDL_RenderPresent(m_renderer.get());
}

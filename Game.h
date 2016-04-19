#ifndef GAME_H
#define GAME_H

#include "SDLDeleter.h"
#include "SDLGameObject.h"
#include "GameStateMachine.h"
#include <SDL.h>
#include <vector>
#include <string>
#include <memory>
class Game
{
public:
	static Game * instance();

	void handleEvents();
	void endGame() { m_running = false; }
	void update();
	void addGameObjects();
	void render();
	bool init(const char* title, int w, int h);
	bool isRunning() const { return m_running; }


	//Getters
	SDL_Window* getWindow() const { return m_window.get(); }
	SDL_Surface* getWindowSurface() const { return m_windowSurface.get(); }
	SDL_Renderer* getRenderer() const { return m_renderer.get(); }
	std::vector<SDLGameObject*> getGameObjects() { return m_gameObjects; }
	//std::unique_ptr<SDL_Window, SDLDeleter> getWindow() const { return m_window; }
	
	std::string getMessage() const { return "Hello World."; }

private:
	Game();
	~Game();
	bool m_running;
	int m_sizeWidth;
	int m_sizeHeight;

	std::unique_ptr<SDL_Window, SDLDeleter> m_window;
	std::unique_ptr<SDL_Renderer, SDLDeleter> m_renderer;
	std::unique_ptr<SDL_Surface, SDLDeleter> m_windowSurface;

	std::vector<SDLGameObject*> m_gameObjects;
	GameStateMachine m_gameStateMachine;
	//std::unique_ptr<std::string, Deleter> m_window;

	static Game * sm_instance;
};
#endif // !GAME_H


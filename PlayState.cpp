#include "PlayState.h"
#include "SDLGameObject.h"
#include "Game.h"

const std::string PlayState::m_ID = "PlayState";

PlayState::PlayState()
{
}


PlayState::~PlayState()
{
}

void PlayState::draw()
{
	//Draw all game objects
	for (auto gameObject : Game::instance()->getGameObjects())
	{
		gameObject->draw();
	}
}

void PlayState::update()
{
	//Update all game objects
	for (auto &gameObject : Game::instance()->getGameObjects())
	{
		gameObject->update();
	}
}

void PlayState::onEnter()
{
	Game::instance()->addGameObjects(); //Add neccessary game objects
}

void PlayState::onExit()
{

}

#include "TextureManager.h"
#include "SDLDeleter.h"
#include "Game.h"
#include <assert.h>
#include <SDL_image.h>

TextureManager * TextureManager::sm_instance = nullptr;

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}


TextureManager * TextureManager::instance()
{
	if (sm_instance == nullptr) {
		sm_instance = new TextureManager();
	}
	return sm_instance;
}

void TextureManager::draw(float x, float y, int w, int h, const std::string & textureID)
{
	SDL_Rect srcRect;
	SDL_Rect dstRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = dstRect.w = w;
	srcRect.h = dstRect.h = h;
	dstRect.x = x;
	dstRect.y = y;

	SDL_RenderCopy(Game::instance()->getRenderer(), m_textures[textureID], &srcRect, &dstRect);
}

void TextureManager::load(const std::string& textureID, const std::string& path)
{

	//std::unique_ptr<SDL_Surface, SDLDeleter> loadedSurface(IMG_Load(path.c_str()), SDLDeleter());
	//assert(loadedSurface != nullptr);

	//SDL_Surface* optimizedSurface = SDL_ConvertSurface(loadedSurface.get(), Game::instance()->getWindowSurface()->format, 0);
	////std::unique_ptr<SDL_Surface, SDLDeleter> optimizedSurface(SDL_ConvertSurface(loadedSurface.get(), Game::instance()->getWindowSurface()->format, 0), SDLDeleter());
	//assert(optimizedSurface != nullptr);


	//std::unique_ptr<SDL_Texture, SDLDeleter> loadedTexture(SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), optimizedSurface), SDLDeleter());
	//assert(loadedTexture != nullptr);

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	SDL_Surface* optimizedSurface = SDL_ConvertSurface(loadedSurface, Game::instance()->getWindowSurface()->format, 0);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), optimizedSurface);

	m_textures[textureID] = texture;
}
//
//SDL_Surface* TextureManager::loadSurface(const std::string& path)
//{
//
//
//	return optimizedSurface;
//}
//
//SDL_Texture * TextureManager::loadTexture(const std::string & path)
//{
//
//	return loadedTexture.get();
//}



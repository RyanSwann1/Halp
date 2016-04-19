#ifndef PLAYER_H
#define PLAYER_H

#include "SDLGameObject.h"
#include "Vector2D.h"
#include <string>
class Player :
	public SDLGameObject
{
public:
	Player();
	~Player();

	void draw() override;
	void update() override;
	void handleEvents() override;

private:
	//Starting position of player
	int m_startXPos;
	int m_startYPos;
	//Size of player
	int m_sizeWidth;
	int m_sizeHeight;


	Vector2D m_position;
	Vector2D m_velocity;
	static const std::string m_ID;
};

#endif // !PLAYER_H
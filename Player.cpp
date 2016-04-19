#include "Player.h"
#include "TextureManager.h"
#include "InputManager.h"

const std::string Player::m_ID = "Player";

Player::Player()
{
	m_sizeHeight = 50;
	m_sizeWidth = 50;
	m_startXPos = 100;
	m_startYPos = 100;
	int movementSpeed = 4;

	m_position.m_x = m_startXPos;
	m_position.m_y = m_startYPos;
}

Player::~Player()
{
}

void Player::draw()
{
	TextureManager::instance()->draw(m_position.m_x, m_position.m_y, m_sizeWidth, m_sizeHeight, m_ID);
	printf("Drawing.");
}

void Player::update()
{

	m_position += m_velocity; //Update player position
}

void Player::handleEvents()
{
	//TextureManager::instnace()->
}


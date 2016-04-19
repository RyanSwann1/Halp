#ifndef SDLGameObject_H
#define SDLGameObject_H

class SDLGameObject
{
public:
	SDLGameObject();
	~SDLGameObject();

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void handleEvents() = 0;

private:

};
#endif // !SDLGameObject_H

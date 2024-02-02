#pragma once
#include <Vector2.h>
#include <Transform.h>
#include <Object.h>

#include "Bullet.h"

class Player
{
public:

	Player();
	~Player();

	

	void Move(char* keys, char* preKeys);
	void Draw();

	float GetPlayerx() { return object.x; }
	float GetPlayery() { return object.y; }
	float GetPlayerradius() { return object.radius; }
	float GetPlayerspeed() { return object.speed; }
	int GetPlayerisalive() { return isalive_; }

	void SetPlayerx(float x) { object.x = x; }
	void SetPlayery(float y) { object.y = y; }
	void SetPlayerradius(float radius) { object.radius = radius; }
	void SetPlayerspeed(float speed)   { object.speed = speed; }
	void SetPlayerisalive(int i) { isalive_ = i; }

	Bullet* bullet_;

private:
	Object object;
	int isalive_;
	

};


#pragma once
#include <Object.h>

class Bullet
{
public:

	void Update();
	void Draw();


	Bullet();
	~Bullet();

	int GetisShot() { return isshot; }
	float GetBulletx() { return bullet.x; }
	float GetBullety() { return bullet.y; }
	float GetBulletradius() { return bullet.radius; }
	float GetBulletspeed() { return bullet.speed; }


	void SetBulletx(float x) { bullet.x = x; }
	void SetBullety(float y) { bullet.y = y; }
	void SetBulletradius(float radius) { bullet.radius=radius; }
	void SetBulletspeed(float speed) { bullet.speed = speed; }
	void SetisShot(int s) {isshot = s;}

private:

	Object bullet;
	int isshot;




};


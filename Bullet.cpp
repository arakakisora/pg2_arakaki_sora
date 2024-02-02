#include "Bullet.h"

#include <Novice.h>



Bullet::Bullet()
{
	bullet.x = 0;
	bullet.y = 0;
	bullet.speed = 5;
	bullet.radius = 10;
	isshot = 0;

}

Bullet::~Bullet()
{


}

void Bullet::Update()
{
	if (isshot == 1) {

		bullet.y -= bullet.speed;

	}

	if (bullet.y <= 0) {
		isshot = 0;

	}
		
}


void Bullet::Draw()
{

	Novice::DrawEllipse(int(bullet.x), int(bullet.y), (int)bullet.radius, (int)bullet.radius, 0.0f, RED, kFillModeSolid);

}


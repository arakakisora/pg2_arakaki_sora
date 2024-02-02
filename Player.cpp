#include "Player.h"
#include <Novice.h>
#include <Transform.h>
#include "Bullet.h"

Player::Player() {
	
	bullet_ = new Bullet();
	object.x = 600;
	object.y = 600;
	object.radius = 30;
	object.speed = 10;
	isalive_ = 1;

}

Player::~Player() {

	delete bullet_;

}





void Player::Move(char *keys,char* preKeys)
{
	if (GetPlayerisalive() == 1) {
		if (keys[DIK_W]) {

			object.y -= object.speed;
		}

		if (keys[DIK_S]) {

			object.y += object.speed;
		}

		if (keys[DIK_D]) {

			object.x += object.speed;
		}

		if (keys[DIK_A]) {

			object.x -= object.speed;
		}

		if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {

			bullet_->SetisShot(1);

		}

		if (bullet_->GetisShot() == 0) {

			bullet_->SetBulletx(object.x);
			bullet_->SetBullety(object.y);


		}

		bullet_->Update();

	}

}


void Player::Draw()
{
	if (isalive_ == 1) {

		Novice::DrawEllipse(int(object.x), int(object.y), int(object.radius), int(object.radius), 0.0f, 0xFFFFFFFF, kFillModeSolid);
	}

	if (bullet_->GetisShot() == 1) {

		bullet_->Draw();

	}


}

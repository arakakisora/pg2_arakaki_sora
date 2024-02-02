#include "Enemy.h"
#include <GetColor.h>


Enemy::Enemy()
{

	enemypos_.x = 300;
	enemypos_.y = 100;
	enemyradius_ = 30;
	isHit_ = 1;
	
	playerrespawntimer_ = 60;
	enemyspeed_ = 5;
	enemyhitpoint = 300;
	enemyhit = 0;
	enemyalpha = 0;
}

Enemy::~Enemy()
{
}

void Enemy::Move()
{
	
	
	enemypos_.x += enemyspeed_;

	if (enemypos_.x > 1200 || enemypos_.x < 0) {

		enemyspeed_ *= -1;

	}
	
	


}

void Enemy::Draw()
{
	if (isHit_ == 1) {
		Novice::DrawEllipse(int(enemypos_.x), int(enemypos_.y), int(enemyradius_), int(enemyradius_), 0.0f, RED, kFillModeSolid);
		
		
		
	}

	Novice::ScreenPrintf(100, 50, "%d", enemyhitpoint);
}

void Enemy::Collision(Player* player_)
{

	float distance;
	float between1;
	float between2;

	between1 = enemypos_.x - player_->bullet_->GetBulletx();
	between2 = enemypos_.y - player_->bullet_->GetBullety();

	distance = sqrtf(between1 * between1 + between2 * between2);

	//弾と敵
	if (player_->bullet_->GetisShot() == 1) {
		if (distance <= enemyradius_ + player_->bullet_->GetBulletradius()) {

			

				
			player_->bullet_->SetisShot(0);
		    enemyhitpoint -= 100;
			
			
			

		}
		
		
	}

	

	if (enemyhitpoint <= 0) {

		isHit_ = 0;
	}

	


	//自機と敵
	float between3 = enemypos_.x - player_->GetPlayerx();
	float between4 = enemypos_.y - player_->GetPlayery();

	float distance2 = sqrtf(between3 * between3 + between4 * between4);

	if (distance2 <= enemyradius_ + player_->GetPlayerradius()) {

		player_->SetPlayerisalive(0);

		player_->SetPlayerx(300);
		player_->SetPlayery(600);

	}

	if (player_->GetPlayerisalive() == 0) {

		playerrespawntimer_--;

	}
	else {
		playerrespawntimer_ = 60;
	}

	if (playerrespawntimer_ <= 0) {

		player_->SetPlayerisalive(1);

	}


}







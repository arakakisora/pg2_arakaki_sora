#pragma once
#include <Vector2.h>
#include <math.h>
#include<Novice.h> 
#include"Player.h"

class Enemy 
{
public:

	void Move();
	void Draw();
	void Collision(Player* player_);
	Enemy();
	~Enemy();

	
	float GetEnemyposx() { return enemypos_.x; }
	float GetEnemyposy() { return enemypos_.y; }
	float GetEnemyradius() { return enemyradius_; }
	bool  GetisEnemyisHit() { return isHit_; }
	//int  GetEnemyspawntimer() { return enemyrespawntimer_; }
	int GetPlayerrespawntimer() { return playerrespawntimer_; }
	float GetEnemyspeed() { return enemyspeed_; }
	int GetEnemyhitpint() { return enemyhitpoint; }

	void SetEnemyposx(float posx) { enemypos_.x = posx; }
	void SetEnemyposy(float posy) { enemypos_.y = posy; }
	void SetEnemyradius(float radius) { enemyradius_ = radius; }
	void SetisEnemyisHit(bool ishit) { isHit_ = ishit; }
	//void SetEnemyspawntimer(int timer) { enemyrespawntimer_ = timer; }
	void SetPlayerrespawntimer(int timer) { playerrespawntimer_ = timer; }
	void SetEnemyspeed(float speed) { enemyspeed_ = speed; }
	void Setenemyhitpoint(int hitpoint) { enemyhitpoint = hitpoint; }
	
private:
	Vector2 enemypos_;
	float enemyradius_;
	bool isHit_;
	//int enemyrespawntimer_;
	int playerrespawntimer_;
	float enemyspeed_;
	float enemyhit;
	int enemyhitpoint;
	int enemyalpha;
	

	

	
	


};


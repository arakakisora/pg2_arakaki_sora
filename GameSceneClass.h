#pragma once
#include "Player.h"
#include "Enemy.h"
class GameSceneClass
{
private:
	enum gamescene {

		title,
		stag1,
		end,


	};
	int alphatitle = 255;
	int start = 0;

	int nowscene;
	int tx = Novice::LoadTexture("./Sprite-0001.png");
	int txend = Novice::LoadTexture("./end.png");
public:

	GameSceneClass();
	~GameSceneClass();

	void Move(char *keys,char* preKeys, GameSceneClass* gamescene);
	void Draw();
	void Init();

	Player* player;
	Enemy* enemy1 ;


};


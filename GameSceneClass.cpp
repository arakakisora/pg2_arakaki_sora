#include "GameSceneClass.h"
#include "Novice.h"
#include <GetColor.h>



GameSceneClass::GameSceneClass()
{

	 nowscene= title;
	  alphatitle = 255;
	  start = 0;
	 player = new Player();
	 enemy1 = new Enemy();
	
}

GameSceneClass::~GameSceneClass()
{

}

void GameSceneClass::Move(char* keys, char* preKeys, GameSceneClass* gamescene)
{
	switch (nowscene)
	{
	case title:
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		
			start = 1;

		}

		

			if (start == 1) {

				if (alphatitle > 0) {
					alphatitle -= 2;
				}

			}

			if (alphatitle < 0) {

				nowscene = stag1;
			}

		break;
	case stag1:



		player->Move(keys, preKeys);
		enemy1->Move();
		enemy1->Collision(player);

		if (enemy1->GetisEnemyisHit() == 0) {
			nowscene = end;
		}


		break;
	case end:

		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			gamescene->Init();
			nowscene = title;
			

		}

		break;
	
	}


}

void GameSceneClass::Draw()
{

	switch (nowscene)
	{
	case title:

		// Novice::DrawBox(0,0, 1300, 800, 0.0f, GetColor(255, 255, 255, alphatitle),kFillModeSolid);
		 Novice::DrawSprite(0, 0 ,tx, 1, 1, 0.0f, GetColor(255, 255, 255, alphatitle));

		break;
	case stag1:

		player->Draw();
		enemy1->Draw();

		break;
	case end:

		Novice::DrawSprite(0, 0, txend, 1, 1, 0.0f, GetColor(255, 255, 255, 255));

		break;

	}

}

void GameSceneClass::Init()
{
	alphatitle = 255;
	start = 0;
	player = new Player();
	enemy1 = new Enemy();

}

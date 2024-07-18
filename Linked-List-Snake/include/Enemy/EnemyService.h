#pragma once
#include "Level/LevelConfig.h"
#include "LinkedListLib/Node.h"

namespace Enemy
{
	class HunterSnakeController;
	class EnemyService
	{
		bool bossLevel;
		HunterSnakeController* hunter_snake_controller;
		void createController();

		void destroy();
	public:
		EnemyService();
		~EnemyService();

		void initialize();
		void update();
		void render();

		void spawnEnemy(Level::LinkedListType level_type);
		bool processSnakeCollision(LinkedListLib::Node* head);
	};
}

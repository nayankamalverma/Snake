#include "Enemy/EnemyService.h"
#include "Level/LevelConfig.h"
#include "Enemy/HunterSnakeController.h"

namespace Enemy
{
	using namespace Level;

	EnemyService::EnemyService()
	{
		hunter_snake_controller = nullptr;
		bossLevel = false;
		createController();
	}

	EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::createController()
	{
		hunter_snake_controller = new HunterSnakeController();
	}

	void EnemyService::initialize()
	{
		hunter_snake_controller->initialize();
	}

	void EnemyService::spawnEnemy(LinkedListType level_type)
	{
		hunter_snake_controller->createLinkedList(level_type);
		hunter_snake_controller->spawnSnake();
		bossLevel = true;
	}

	void EnemyService::update()
	{
		if(bossLevel) hunter_snake_controller->update();
	}

	void EnemyService::render()
	{
		if (bossLevel) hunter_snake_controller->render();
	}

	bool EnemyService::processSnakeCollision(Node* head)
	{
		if (!bossLevel)return false;
		return hunter_snake_controller->processSnakeCollision(head);
	}


	void EnemyService::destroy()
	{
		delete(hunter_snake_controller);
	}

}

#include "Enemy/EnemyService.h"
#include "Level/LevelConfig.h"
#include "Enemy/HunterSnakeController.h"

namespace Enemy
{
	using namespace Level;

	EnemyService::EnemyService()
	{
		hunter_snake_controller = nullptr;
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
	}

	void EnemyService::update()
	{
		hunter_snake_controller->update();
	}

	void EnemyService::render()
	{
		hunter_snake_controller->render();
	}

	void EnemyService::destroy()
	{
		delete(hunter_snake_controller);
	}

}

﻿#include "Player/SnakeController.h"
#include "Global/ServiceLocator.h"
#include "Level/LevelService.h"
#include "Event/EventService.h"
#include "Element/ElementService.h"
#include "Food/FoodService.h"
#include "Global/Config.h"
#include "LinkedListLib/SingleLinked/SingleLinkedList.h"
#include "LinkedListLib/DoubleLinked/DoubleLinkedList.h"

namespace Player
{
	using namespace LinkedListLib;
	using namespace SingleLinked;
	using namespace DoubleLinked;
	using namespace Global;
	using namespace Level;
	using namespace Event;
	using namespace Time;
	using namespace Sound;
	using namespace Element;
	using namespace Food;

	SnakeController::SnakeController()
	{
		linked_list = nullptr;
	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::createLinkedList(LinkedListType level_type)
	{
		switch (level_type)
		{
		case LinkedListType::SINGLE_LINKED_LIST:
			linked_list = new SingleLinkedList();
			break;
		case LinkedListType::DOUBLE_LINKED_LIST:
			linked_list = new DoubleLinkedList();
			break;
		}

		initializeLinkedList();
	}

	void SnakeController::initializeLinkedList()
	{
		float width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		reset();
		linked_list->initialize(Config::snake_body_texture_path ,width, height, default_position, default_direction,sf::Color::Green);
	}

	void SnakeController::initialize() { }

	void SnakeController::update()
	{
		switch (current_snake_state)
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			delayedUpdate();
			handleSpeedBoost();
			break;

		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}

	void SnakeController::render()
	{
		linked_list->render();
	}

	void SnakeController::processPlayerInput()
	{
		if (current_input_state == InputState::PROCESSING)
			return;

		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedUpArrowKey() && current_snake_direction != Direction::DOWN)
		{
			current_snake_direction = Direction::UP;
			current_input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedDownArrowKey() && current_snake_direction != Direction::UP)
		{
			current_snake_direction = Direction::DOWN;
			current_input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedLeftArrowKey() && current_snake_direction != Direction::RIGHT)
		{
			current_snake_direction = Direction::LEFT;
			current_input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedRightArrowKey() && current_snake_direction != Direction::LEFT)
		{
			current_snake_direction = Direction::RIGHT;
			current_input_state = InputState::PROCESSING;
		}
	}

	void SnakeController::delayedUpdate()
	{
		elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (elapsed_duration >= movement_frame_duration)
		{
			elapsed_duration = 0.f;
			updateSnakeDirection();
			processSnakeCollision();

			if (current_snake_state != SnakeState::DEAD)
				moveSnake();
			current_input_state = InputState::WAITING;
		}
	}

	void SnakeController::updateSnakeDirection()
	{
		linked_list->updateNodeDirection(current_snake_direction);
	}

	void SnakeController::moveSnake()
	{
		linked_list->updateNodePosition();
	}

	void SnakeController::processSnakeCollision()
	{
		processBodyCollision();
		processElementsCollision();
		processFoodCollision();
		processHunterSnakeCollision();
	}

	void SnakeController::processBodyCollision()
	{
		if (linked_list->processNodeCollision())
		{
			snakeDead();
		}
	}

	void SnakeController::processElementsCollision()
	{
		ElementService* element_service = ServiceLocator::getInstance()->getElementService();

		if (element_service->processElementsCollision(linked_list->getHeadNode()))
		{
			snakeDead();
		}
	}

	void SnakeController::processFoodCollision()
	{
		FoodService* food_service = ServiceLocator::getInstance()->getFoodService();
		FoodType food_type;

		if (food_service->processFoodCollision(linked_list->getHeadNode(), food_type))
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::PICKUP);

			food_service->destroyFood();
			OnFoodCollected(food_type);

			player_score++;
		}
	}

	void SnakeController::processHunterSnakeCollision()
	{
		Enemy::EnemyService* enemy_service = ServiceLocator::getInstance()->getEnemyService();
		if (enemy_service->processSnakeCollision(linked_list->getHeadNode()))
		{
			snakeDead();
		}
	}


	void SnakeController::OnFoodCollected(FoodType food_type)
	{
		switch (food_type)
		{
		case FoodType::PIZZA:
			//Insert at TAIL
			linked_list->insertNodeAtTail();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::INSERT_AT_TAIL;
			break;

		case FoodType::BURGER:
			//Insert at HEAD
			linked_list->insertNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			last_linked_list_operation = LinkedListOperations::INSERT_AT_HEAD;
			break;

		case FoodType::CHEESE:
			//Insert at MIDDLE
			linked_list->insertNodeAtMiddle();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::INSERT_AT_MID;
			break;

		case FoodType::APPLE:
			//Delete at HEAD
			linked_list->removeNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			last_linked_list_operation = LinkedListOperations::REMOVE_AT_HEAD;
			break;

		case FoodType::MANGO:
			//Delete at MIDDLE
			linked_list->removeNodeAtMiddle();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REMOVE_AT_MID;
			break;

		case FoodType::ORANGE:
			//Delete at TAIL
			linked_list->removeNodeAtTail();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REMOVE_AT_TAIL;
			break;

		case FoodType::POISION:
			//Delete half nodes
			linked_list->removeHalfNodes();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::DELETE_HALF_LIST;
			break;

		case FoodType::ALCOHOL:
			//Reverse Direction
			current_snake_direction = linked_list->reverse();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REVERSE_LIST;
			break;
		case FoodType::BOOSTER:
			printf("I FEEL THE NEED... THE NEED FOR SPEED.\n");
			speedBooster = true;
			movement_frame_duration = 0.05f;
			speed_boost_elapsed_duration = 0;
			break;
		}
	}

	void SnakeController::handleRestart()
	{
		restart_counter += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (restart_counter >= restart_duration)
		{
			respawnSnake();
		}
	}

	void SnakeController::handleSpeedBoost()
	{
		speed_boost_elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		if(speed_boost_elapsed_duration>=speed_boost_duration)
		{
			movement_frame_duration = 0.1f;
			speedBooster = false;
		}
	}


	void SnakeController::spawnSnake()
	{
		for (int i = 0; i < initial_snake_length; i++)
		{
			linked_list->insertNodeAtTail();
		}
	}

	void SnakeController::reset()
	{
		printf("reset");
		current_snake_state = SnakeState::ALIVE;
		current_snake_direction = default_direction;

		time_complexity = TimeComplexity::ONE;
		elapsed_duration = 0.f;
		restart_counter = 0.f;
		player_score = 0;
		speedBooster = false;
		current_input_state = InputState::WAITING;
		time_complexity = TimeComplexity::NONE;
		last_linked_list_operation = LinkedListOperations::NONE;
	}

	void SnakeController::respawnSnake()
	{
		linked_list->removeAllNodes();
		reset();

		spawnSnake();
	}

	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}

	SnakeState SnakeController::getSnakeState()
	{
		return current_snake_state;
	}

	int SnakeController::getPlayerScore()
	{
		return player_score;
	}

	TimeComplexity SnakeController::getTimeComplexity()
	{
		return time_complexity;
	}

	LinkedListOperations SnakeController::getLastOperation()
	{
		return last_linked_list_operation;
	}

	int SnakeController::getSnakeSize()
	{
		return linked_list->getLinkedListSize();
	}

	bool SnakeController::isSnakeDead()
	{
		return current_snake_state == SnakeState::DEAD;
	}


	int SnakeController::getRandomBodyPartIndex()
	{
		return std::rand() % (linked_list->getLinkedListSize() - 1);
	}

	std::vector<sf::Vector2i> SnakeController::getCurrentSnakePositionList()
	{
		return linked_list->getNodesPositionList();
	}

	void SnakeController::destroy()
	{
		delete (linked_list);
	}

	bool SnakeController::isSnakeSizeMinimum()
	{
		if (linked_list->getLinkedListSize() <= minimum_snake_size)
			return true;
		return false;
	}

	bool SnakeController::isSpeedBoost()
	{
		return speedBooster;
	}

	float SnakeController::getSpeedBoostTime()
	{
		return speed_boost_elapsed_duration;
	}

	void SnakeController::snakeDead()
	{
		current_snake_state = SnakeState::DEAD;
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
	}


}
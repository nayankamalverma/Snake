#include "Enemy/HunterSnakeController.h"

#include "Global/Config.h"
#include "Global/ServiceLocator.h"
#include "LinkedListLib/SingleLinked/SingleLinkedList.h"
#include "LinkedListLib/DoubleLinked/DoubleLinkedList.h"

namespace Enemy
{
	using namespace Global;
	using namespace Event;

	HunterSnakeController::HunterSnakeController()
	{
		linked_list = nullptr;
	}

	HunterSnakeController::~HunterSnakeController()
	{
		destroy();
	}

	

	void HunterSnakeController::createLinkedList(LinkedListType level_type)
	{
		switch (level_type)
		{
		case LinkedListType::SINGLE_LINKED_LIST:
			linked_list = new SingleLinked::SingleLinkedList();
			break;
		case LinkedListType::DOUBLE_LINKED_LIST:
			linked_list = new DoubleLinked::DoubleLinkedList();
			break;
		}

		initializeLinkedList();
	}

	void HunterSnakeController::initializeLinkedList()
	{
		float width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		reset();
		linked_list->initialize(Config::hunter_snake_body_texture_path ,width, height, default_position, default_direction,sf::Color::Red);

	}

	void HunterSnakeController::initialize(){}

	void HunterSnakeController::update()
	{
		current_snake_state = ServiceLocator::getInstance()->getPlayerService()->getSnakeState();
		switch (current_snake_state)
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			delayedUpdate();
			break;

		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}

	void HunterSnakeController::render()
	{
		linked_list->render();
	}

	void HunterSnakeController::processPlayerInput()
	{
		if (current_input_state == InputState::PROCESSING)
			return;

		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedUpArrowKey() && current_snake_direction != Direction::UP)
		{
			current_snake_direction = Direction::DOWN;
			current_input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedDownArrowKey() && current_snake_direction != Direction::DOWN)
		{
			current_snake_direction = Direction::UP;
			current_input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedLeftArrowKey() && current_snake_direction != Direction::LEFT)
		{
			current_snake_direction = Direction::RIGHT;
			current_input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedRightArrowKey() && current_snake_direction != Direction::RIGHT)
		{
			current_snake_direction = Direction::LEFT;
			current_input_state = InputState::PROCESSING;
		}
	}

	void HunterSnakeController::delayedUpdate()
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

	void HunterSnakeController::updateSnakeDirection()
	{
		linked_list->updateNodeDirection(current_snake_direction);
	}

	
	void HunterSnakeController::moveSnake()
	{
	  linked_list->updateNodePosition();
	}


	void HunterSnakeController::processSnakeCollision()
	{
			  //snakecontroller proccessbodycollision
	}

	

	void HunterSnakeController::handleRestart()
	{
		restart_counter += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (restart_counter >= restart_duration)
		{
			respawnSnake();
		}
	}

	void HunterSnakeController::respawnSnake()
    {
		linked_list->removeAllNodes();
		reset();
		spawnSnake();
	}

	void HunterSnakeController::spawnSnake()
	{
		for (int i = 0; i < snake_length; i++)
		{
			linked_list->insertNodeAtTail();
		}
	}

	void HunterSnakeController::reset()
	{
		current_snake_direction = default_direction;
		elapsed_duration = 0.f;
		restart_counter = 0.f;
	}

	void HunterSnakeController::destroy()
	{
		delete(linked_list);
	}
}

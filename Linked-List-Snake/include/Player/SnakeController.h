#pragma once
#include "Food/FoodItem.h"
#include "Player/Direction.h"
#include "LinkedList/SingleLinkedList.h"

namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};

	enum class InputState
	{
		WAITING,
		PROCESSING
	};

	class SnakeController
	{
		const int initial_snake_length = 10;
		const float movement_frame_duration = 0.1f;
		const float restart_duration = 2.f;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;

		float elapsed_duration;
		float restart_counter;

		Direction current_snake_direction;
		SnakeState current_snake_state;
		InputState 	current_input_state;

		LinkedList::SingleLinkedList* single_linked_list;
		void createLinkedList();

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void processBodyCollision();
		void processElementsCollision();
		void processFoodCollision();
		void OnFoodCollected(Food::FoodType type);
		void handleRestart();
		void delayedUpdate();
		void reset();
		void destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void spawnSnake();
		void respawnSnake();
		std::vector<sf::Vector2i> getCurrentSnakePositionList();
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
	};
}

#pragma once
#include <SFML/System/Vector2.hpp>

#include "Player/Direction.h"
#include "Player/SnakeController.h"


namespace Enemy
{
	using namespace Player;

	class HunterSnakeController
	{
		const int snake_length = 15;
		const float movement_frame_duration = 0.1f;  //snake position frame update speed
		const float restart_duration = 3.f;

		const sf::Vector2i default_position = sf::Vector2i(30, 13);
		const Direction default_direction = Direction::LEFT;

		float elapsed_duration;
		float restart_counter;

		Direction current_snake_direction;
		InputState current_input_state;

		LinkedList* linked_list;
		SnakeState current_snake_state;

		void initializeLinkedList();

		void processPlayerInput();
		void updateSnakeDirection();
		void delayedUpdate();
		void moveSnake();
		void processSnakeCollision();

		void handleRestart();

		void reset();
		void destroy();
	public:
		HunterSnakeController();
		~HunterSnakeController();

		void initialize();
		void update();
		void render();

		void createLinkedList(LinkedListType level_type);
		void spawnSnake();
		void respawnSnake();

	};
}

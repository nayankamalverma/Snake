﻿#pragma once
#include <SFML/Graphics.hpp>
#include "Player/Direction.h"
#include "LinkedList/SingleLinkedList.h"

namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};

	class SnakeController
	{
		const int initial_snake_length = 10;
		const float movement_frame_duration = 0.1f;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;

		float 	elapsed_duration;

		Direction current_snake_direction;
		SnakeState current_snake_state;

		LinkedList::SingleLinkedList* single_linked_list;
		void createLinkedList();

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
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
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
	};
}

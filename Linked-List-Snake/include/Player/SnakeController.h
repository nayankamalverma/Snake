#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedListLib/Node.h"
#include "LinkedListLib/LinkedList.h"
#include "Food/FoodType.h"
#include "Level/LevelConfig.h"

namespace Player
{
	using namespace Level;
	using namespace Food;
	using namespace LinkedListLib;

	enum class TimeComplexity
	{
		NONE,
		ONE,
		N,
	};

	enum class LinkedListOperations
	{
		NONE,
		INSERT_AT_HEAD,
		INSERT_AT_TAIL,
		INSERT_AT_MID,
		REMOVE_AT_HEAD,
		REMOVE_AT_TAIL,
		REMOVE_AT_MID,
		DELETE_HALF_LIST,
		REVERSE_LIST,
	};

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
	private:
		const int initial_snake_length = 10;
		float movement_frame_duration = 0.1f;  //snake position frame update speed
		const float restart_duration = 3.f;
		const float speed_boost_duration = 8.f;			//speed boost duration

		const int minimum_snake_size = 3;

		const sf::Vector2i default_position = sf::Vector2i(13, 13);
		const Direction default_direction = Direction::RIGHT;

		SnakeState current_snake_state;
		float speed_boost_elapsed_duration;
		float elapsed_duration;
		float restart_counter;
		Direction current_snake_direction;
		InputState current_input_state;

		bool speedBooster;
		int player_score;
		TimeComplexity time_complexity;
		LinkedListOperations last_linked_list_operation;

		LinkedList* linked_list;

		void initializeLinkedList();

		void processPlayerInput();
		void updateSnakeDirection();
		void delayedUpdate();
		void moveSnake();
		void processSnakeCollision();

		void processBodyCollision();
		void processElementsCollision();
		void processFoodCollision();
		void processHunterSnakeCollision();

		void OnFoodCollected(FoodType food_type);
		int getRandomBodyPartIndex();

		void handleSpeedBoost();
		void handleRestart();
		void snakeDead();
		void reset();
		void destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void createLinkedList(LinkedListType level_type);
		void spawnSnake();
		void respawnSnake();
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();

		std::vector<sf::Vector2i> getCurrentSnakePositionList();
		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();
		int getPlayerScore();
		bool isSnakeDead();
		int getSnakeSize();
		bool isSnakeSizeMinimum();
		bool isSpeedBoost();
		float getSpeedBoostTime();
		
	};
}
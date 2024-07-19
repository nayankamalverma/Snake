#include "Element/Obstacle.h"

#include "Element/ElementData.h"
#include "Level/LevelView.h"
#include "Global/Config.h"

namespace Element
{
	using namespace Global;
	using namespace Level;
	using namespace UI::UIElement;

	Obstacle::Obstacle()
	{
		obstacle_image = new ImageView();
	}

	Obstacle::~Obstacle()
	{
		delete (obstacle_image);
	}

	void Obstacle::initialize(sf::Vector2i grid_pos, float width, float height,ElementType type)
	{
		grid_position = grid_pos;
		cell_width = width;
		cell_height = height;
		element_type = type;

		initializeObstacleImage();
	}

	void Obstacle::initializeObstacleImage()
	{
		sf::Vector2f screen_position = getObstacleImagePosition();
		if(ElementType::MOVING_OBSTACLE == element_type) obstacle_image->initialize(Config::obstacle_texture_path, cell_width*5, cell_height, screen_position);
		else obstacle_image->initialize(Config::obstacle_texture_path, cell_width, cell_height, screen_position);

		obstacle_image->show();
	}

	void Obstacle::update()
	{
		if (element_type == ElementType::MOVING_OBSTACLE)move();
		obstacle_image->update();
	}

	void Obstacle::move()
	{
		// Logic for moving the obstacle
		// For example, let's move the obstacle one cell to the right every update
		grid_position.x += 1;  // Move to the right
		sf::Vector2f new_position = getObstacleImagePosition();
		obstacle_image->setPosition(new_position);  // You may need to add setPosition method in ImageView class
	}

	void Obstacle::render()
	{
		obstacle_image->render();
	}
	sf::Vector2i Obstacle::getObstaclePosition()
	{
		return grid_position;
	}


	sf::Vector2f Obstacle::getObstacleImagePosition()
	{
		float screen_position_x = LevelView::border_offset_left + (cell_width * grid_position.x);
		float screen_position_y = LevelView::border_offset_top + (cell_height * grid_position.y);

		return sf::Vector2f(screen_position_x, screen_position_y);
	}



}
﻿#include "Player/BodyPart.h"
#include "Global/ServiceLocator.h"
#include "Level/LevelView.h"
#include "Level/LevelModel.h"
#include "Global/Config.h"

namespace Player
{
	using namespace Global;
	using namespace Level;
	using namespace UI::UIElement;

	BodyPart::BodyPart()
	{
		grid_position = sf::Vector2i(0, 0);
		createBodyPartImage();
	}

	BodyPart::~BodyPart()
	{
		destroy();
	}

	void BodyPart::initialize(float width, float height, sf::Vector2i pos, Direction dir)
	{
		bodypart_width = width;
		bodypart_height = height;
		direction = dir;
		grid_position = pos;

		initializeBodyPartImage();
	}

	void BodyPart::createBodyPartImage()
	{
		bodypart_image = new ImageView();
	}

	void BodyPart::initializeBodyPartImage()
	{
	}

	void BodyPart::updatePosition()
	{
		bodypart_image->setPosition(getBodyPartScreenPosition());
		bodypart_image->setRotation(getRotationAngle());
		bodypart_image->update();
	}

	void BodyPart::render()
	{
		bodypart_image->render();
	}

	Direction BodyPart::getDirection()
	{
		return direction;
	}

	void BodyPart::setDirection(Direction direction)
	{
		this->direction = direction;
	}

	sf::Vector2f BodyPart::getBodyPartScreenPosition()
	{
		float x_screen_position = LevelView::border_offset_left + (grid_position.x * bodypart_width) + (bodypart_width / 2);
		float y_screen_position = LevelView::border_offset_top + (grid_position.y * bodypart_height) + (bodypart_height / 2);

		return sf::Vector2f(x_screen_position, y_screen_position);
	}

	float BodyPart::getRotationAngle()
	{
		switch (direction)
		{
		case Direction::UP:
			return 270.f;
		case Direction::DOWN:
			return 90.f;
		case Direction::RIGHT:
			return 0;
		case Direction::LEFT:
			return 180.f;
		}
	}

	void BodyPart::destroy()
	{
		delete (bodypart_image);
	}
}

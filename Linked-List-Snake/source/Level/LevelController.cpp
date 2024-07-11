﻿#include "Level/LevelController.h"
#include "Level/LevelView.h"

namespace Level
{
	LevelController::LevelController()
	{
		level_model = new LevelModel();
		level_view = new LevelView();
	}

	LevelController::~LevelController()
	{
		delete level_model;
		delete level_view;
	}

	void LevelController::initialize()
	{
		level_view->initialize();
		level_model->initialize(level_view->getGridWidth(), level_view->getGridHeight());
	}

	void LevelController::update()
	{
		level_view->update();
	}

	void LevelController::render()
	{
		level_view->render();
	}

	float LevelController::getCellWidth()
	{
		level_model->getCellWidth();
	}

	float LevelController::getCellHeight()
	{
		level_model->getCellHeight();
	}



	
}

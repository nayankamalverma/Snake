#include "Level/LevelController.h"
#include "Level/LevelView.h"

namespace Level
{
	LevelController::LevelController()
	{
		//level_model = new LevelModel();
		level_view = new LevelView();
	}

	LevelController::~LevelController()
	{
		//delete level_model;
		delete level_view;
	}

	void LevelController::initialize()
	{
		level_view->initialize();
	}
	void LevelController::update()
	{
		level_view->update();
	}
	void LevelController::render()
	{
		level_view->render();
	}


	
}

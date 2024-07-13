#include "Level/LevelModel.h"

namespace Level
{
	LevelModel::LevelModel() = default;

	LevelModel::~LevelModel() = default;

	void LevelModel::initialize(float width, float height)
	{
		cell_width = width / number_of_columns;
		cell_height = height / number_of_rows;
	}

	float LevelModel::getCellWidth()
	{
		return cell_width;
	}

	float LevelModel::getCellHeight()
	{
		return cell_height;
	}
}
#pragma once
#include <vector>
#include "LevelModel.h"

namespace Level
{
    class LevelView;

    class LevelController
    {
    private:
        LevelView* level_view;
        LevelModel* level_model;

    public:
        LevelController();
        ~LevelController();

        void initialize();
        void update();
        void render();

        float getCellWidth();
        float getCellHeight();
    };
}
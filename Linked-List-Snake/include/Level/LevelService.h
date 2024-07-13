﻿#pragma once
#include "Level/LevelNumber.h"

namespace Level
{
    class LevelController;

    class LevelService
    {
    private:
        LevelController* level_controller;
        LevelNumber current_level;

        void createLevelController();
        void spawnPlayer();
        void destroy();

    public:
        LevelService();
        ~LevelService();

        void initialize();
        void update();
        void render();

        float getCellWidth();
        float getCellHeight();
        void createLevel(LevelNumber level_to_load);
    };
}
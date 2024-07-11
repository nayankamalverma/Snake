﻿#pragma once

#include "Level/LevelNumber.h"

namespace Level
{
    struct LevelData
    {
        LevelData(LevelNumber ind)
        {
            level_index = ind;
        }

        LevelNumber level_index;
    };
}
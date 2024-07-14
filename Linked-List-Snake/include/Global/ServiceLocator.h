#pragma once
#include "Element/ElementService.h"
#include "Graphics/GraphicService.h"
#include "Event/EventService.h"
#include "Food/FoodService.h"
#include "UI/UIService.h"
#include "Sound/SoundService.h"
#include "Level/LevelService.h"
#include "Time/TimeService.h"
#include "Player/PlayerService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        Event::EventService* event_service;
        Graphics::GraphicService* graphic_service;
        Sound::SoundService* sound_service;
        Level::LevelService* level_service;
        Element::ElementService* element_service;
        Player::PlayerService* player_service;
        Food::FoodService* food_service;
        UI::UIService* ui_service;
        Time::TimeService* time_service;

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Event::EventService* getEventService();
        Graphics::GraphicService* getGraphicService();
        Sound::SoundService* getSoundService();
        Level::LevelService* getLevelService();
        Element::ElementService* getElementService();
        Player::PlayerService* getPlayerService();
        Food::FoodService* getFoodService();
        UI::UIService* getUIService();
        Time::TimeService* getTimeService();
        void deleteServiceLocator();
    };
}
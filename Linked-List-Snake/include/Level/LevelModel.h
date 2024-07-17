#pragma once
#include <SFML/System/Vector2.hpp>
#include "Level/LevelData.h"
#include <vector>

namespace Level
{
    class LevelModel
    {
        std::vector<Element::ElementData> level_one_element_list;

        std::vector<Element::ElementData> level_two_element_list =
        {
            //TOP-LEFT
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 1)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(2, 1)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(3, 1)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 2)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 3)),

            //TOP-RIGHT
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 1)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 2)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 3)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(47, 1)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(46, 1)),

            //BOTTOM-LEFT
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 26)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 25)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 24)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(2, 26)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(3, 26)),

            //BOTTOM-RIGHT
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 26)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 25)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 24)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(47, 26)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(46, 26)),

            //CENTER-TOP-BAR
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(21, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(22, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(23, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(24, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(26, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(27, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(28, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(29, 11)),

            //CENTER-BOTTOM-BAR
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(21, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(22, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(23, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(24, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(26, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(27, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(28, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(29, 15)),
        };

        std::vector<Element::ElementData>  level_three_element_list = {

            //top verticsl
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20, 1)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20, 2)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20, 3)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20, 4)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20, 5)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20, 6)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20, 7)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20, 8)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20, 9)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20, 10)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20, 12)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20, 13)),

            //down vertical
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 14)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 16)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 17)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 18)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 19)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 20)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 21)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 22)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 23)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 24)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 25)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 26)),

            //left horizontal
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(2,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(3,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(4,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(5,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(6,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(7,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(8,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(9,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(10,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(11,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(12,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(13,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(14,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(15,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(16,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(17,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(18,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(19,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(21,17)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(22,17)),

             //right horizontal
        	 Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(28,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(29,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30,10)),
        	 Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(31,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(32,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(33,10)),
        	 Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(34,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(35,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(36,10)),
        	 Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(37,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(38,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(39,10)),
        	 Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(40,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(41,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(42,10)),
        	 Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(43,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(44,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(45,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(46,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(47,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48,10)),


        };

        std::vector<Element::ElementData>  level_four_element_list = {

            //TOP-LEFT
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 1)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(2, 1)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(3, 1)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 2)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 3)),

            //top center vertical
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 2)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 3)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 4)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 5)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 6)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 7)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 8)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 9)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 10)),

        	//bottom center vertical
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 22)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 23)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 24)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 25)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 26)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 27)),

            //top center horizontal
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(4,1)),//5-8
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(9,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(10,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(11,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(12,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(13,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(14,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(15,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(16,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(17,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(18,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(19,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(21,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(22,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(23,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(24,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(26,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(27,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(28,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(29,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(31,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(32,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(33,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(34,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(35,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(36,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(37,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(38,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(39,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(40,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(41,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(42,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(43,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(44,1)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(45,1)), //46-48

             //center horizontal
        	 Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1,10)),
        	 Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(2,10)),
        	 Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(3,10)),
        	 Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(4,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(5,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(6,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(7,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(8,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(9,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(10,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(11,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(12,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(13,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(14,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(15,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(16,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(17,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(18,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(19,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(21,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(22,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(23,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(24,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25,10)), //26-29
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(31,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(32,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(33,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(34,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(35,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(36,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(37,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(38,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(39,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(40,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(41,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(42,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(43,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(44,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(45,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(46,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(47,10)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48,10)),

        	 //bottom horizontal
        	 Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1,21)),
        	 Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(2, 21)),
        	 Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(3, 21)),
        	 Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(4, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(5, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(6, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(7, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(8, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(9, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(10, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(11, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(12, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(13, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(14, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(15, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(16, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(17, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(18, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(19, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(20, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(21, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(22, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(23, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(24, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(26, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(27, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(28, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(29, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(30, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(31, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(32, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(33, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(34, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(35, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(36, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(37, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(38, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(39, 42)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(40, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(41, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(42, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(43, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(44, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(45, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(46, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(47, 21)),
             Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 21)),
        };


        std::vector<LevelData> level_configurations;

        float cell_width;
        float cell_height;
    	void initializeLevelData();
        
       
    public:
        static const int number_of_rows = 28;
        static const int number_of_columns = 50;

        LevelModel();
        ~LevelModel();

        void initialize(int width, int height);
        const std::vector<Element::ElementData>& getElementDataList(int level_to_load);

        float getCellWidth();
        float getCellHeight();
    };
}
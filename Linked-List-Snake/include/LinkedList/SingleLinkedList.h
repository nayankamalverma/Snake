#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/Node.h"

namespace LinkedList
{

	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};

	class SingleLinkedList
	{
	private:
		Node* head_node;

		float node_width;
		float node_height;

		int linked_list_size;

		sf::Vector2i default_position;
		Direction default_direction;

		Node* createNode();
		sf::Vector2i getNewNodePosition(Node* reference_node,Operation operation);


	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Direction direction);
		void render();

		void initializeNode(Node* new_node, Node* reference_node, Operation operation);
		void insertNodeAtHead();
		void insertNodeAtMiddle();
		void insertNodeAtIndex(int index);
		void insertNodeAtTail();
		int findMiddleNode();
		void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);
		void removeNodeAtHead();
		void removeAllNodes();
		void updateNodePosition();
		void updateNodeDirection(Direction direction_to_set);

		std::vector<sf::Vector2i> getNodesPositionList();
		bool processNodeCollision();
		Node* getHeadNode();
	};
}
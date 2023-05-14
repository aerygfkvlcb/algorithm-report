#pragma once

struct Node {
	int data = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};


class BinaryTree {
public:
	BinaryTree(int _data, Node* rootNode);
	~BinaryTree();
	void AddNode(int _data, Node* rootNode);
	void SearchNode(int _data, Node* rootNode);
	void DeleteNode(int _data, Node* rootNode);
};
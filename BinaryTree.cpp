#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree(int _data, Node* rootNode)
{
	rootNode->data = _data;
	cout << "루트 노드의 값:" << rootNode->data << endl;
	
}

BinaryTree::~BinaryTree()
{
	cout << "소멸자" << endl;
}

void BinaryTree::AddNode(int _data, Node* rootNode)
{
	Node* newNode = new Node;
	Node* tmpRoot = rootNode;
	Node* Root = tmpRoot;
	while (tmpRoot != nullptr) {
		Root = tmpRoot;
		if (_data <= tmpRoot->data) {
			tmpRoot = tmpRoot->left;
		}
		else {
			tmpRoot = tmpRoot->right;
		}
	}
	if (_data <= Root->data) {
		Root->left = newNode;
		newNode->data = _data;
	}
	else {
		Root->right = newNode;
		newNode->data = _data;
	}
	cout << "추가된 값:" << newNode->data << endl;
}

void BinaryTree::SearchNode(int _data, Node* rootNode)
{
	int numDown = 0;
	Node* currentNode = rootNode;
	while (currentNode != nullptr) {
		if (_data == currentNode->data){
			cout << "입력된 값 "<<_data<<" 은(는) 존재하는 값이고 루트 노드로부터 찾는데 " << numDown << "회 걸렸습니다." << endl;
		break;
		}
		else if (_data < currentNode->data)
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
		numDown++;
	}
	if (currentNode == nullptr)
		cout << "입력된 값 "<<_data<<" 은(는) 없는 값입니다." << endl;
	return;
}

void BinaryTree::DeleteNode(int _data, Node* rootNode)
{
	Node* currentNode = rootNode; // 삭제할 노드
	Node* currentRoot = currentNode; // 삭제할 노드의 윗 노드
	while (currentNode->data != _data) { // 삭제할 노드의 값이 입력된 값이 될 때까지 while
		currentRoot = currentNode;
		if (_data < currentNode->data)
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
	}
	if (currentNode->left == nullptr && currentNode->right == nullptr) { // 삭제할 노드의 좌,우가 null일 때
		if (currentNode->data < currentRoot->data) // 삭제할 노드가 윗 노드의 좌측인지, 우측인지 판별
			currentRoot->left = nullptr;
		else
			currentRoot->right = nullptr;
	}
	else if (currentNode->left == nullptr && currentNode->right != nullptr) { // 삭제할 노드의 좌 노드만 null일 때
		if (currentNode->data < currentRoot->data) // 삭제할 노드가 윗 노드의 좌측인지, 우측인지 판별
			currentRoot->left = currentNode->right;
		else
			currentRoot->right = currentNode->right;
	}
	else if (currentNode->right == nullptr && currentNode->left != nullptr) { // 삭제할 노드의 우 노드만 null일 때
		if (currentNode->data < currentRoot->data) // 삭제할 노드가 윗 노드의 좌측인지, 우측인지 판별
			currentRoot->left = currentNode->left;
		else
			currentRoot->right = currentNode->left;
	}
	else {
		Node* minNode = currentNode->right;
		while (minNode->left != nullptr) { // 삭제할 노드의 우측에서 가장 작은노드 찾기(좌측으로 내려가기)
			minNode = minNode->left;
		}
		currentNode->data = minNode->data;
		DeleteNode(minNode->data, currentNode->right);
	}
	return;
}
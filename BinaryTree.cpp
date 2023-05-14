#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree(int _data, Node* rootNode)
{
	rootNode->data = _data;
	cout << "��Ʈ ����� ��:" << rootNode->data << endl;
	
}

BinaryTree::~BinaryTree()
{
	cout << "�Ҹ���" << endl;
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
	cout << "�߰��� ��:" << newNode->data << endl;
}

void BinaryTree::SearchNode(int _data, Node* rootNode)
{
	int numDown = 0;
	Node* currentNode = rootNode;
	while (currentNode != nullptr) {
		if (_data == currentNode->data){
			cout << "�Էµ� �� "<<_data<<" ��(��) �����ϴ� ���̰� ��Ʈ ���κ��� ã�µ� " << numDown << "ȸ �ɷȽ��ϴ�." << endl;
		break;
		}
		else if (_data < currentNode->data)
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
		numDown++;
	}
	if (currentNode == nullptr)
		cout << "�Էµ� �� "<<_data<<" ��(��) ���� ���Դϴ�." << endl;
	return;
}

void BinaryTree::DeleteNode(int _data, Node* rootNode)
{
	Node* currentNode = rootNode; // ������ ���
	Node* currentRoot = currentNode; // ������ ����� �� ���
	while (currentNode->data != _data) { // ������ ����� ���� �Էµ� ���� �� ������ while
		currentRoot = currentNode;
		if (_data < currentNode->data)
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
	}
	if (currentNode->left == nullptr && currentNode->right == nullptr) { // ������ ����� ��,�찡 null�� ��
		if (currentNode->data < currentRoot->data) // ������ ��尡 �� ����� ��������, �������� �Ǻ�
			currentRoot->left = nullptr;
		else
			currentRoot->right = nullptr;
	}
	else if (currentNode->left == nullptr && currentNode->right != nullptr) { // ������ ����� �� ��常 null�� ��
		if (currentNode->data < currentRoot->data) // ������ ��尡 �� ����� ��������, �������� �Ǻ�
			currentRoot->left = currentNode->right;
		else
			currentRoot->right = currentNode->right;
	}
	else if (currentNode->right == nullptr && currentNode->left != nullptr) { // ������ ����� �� ��常 null�� ��
		if (currentNode->data < currentRoot->data) // ������ ��尡 �� ����� ��������, �������� �Ǻ�
			currentRoot->left = currentNode->left;
		else
			currentRoot->right = currentNode->left;
	}
	else {
		Node* minNode = currentNode->right;
		while (minNode->left != nullptr) { // ������ ����� �������� ���� ������� ã��(�������� ��������)
			minNode = minNode->left;
		}
		currentNode->data = minNode->data;
		DeleteNode(minNode->data, currentNode->right);
	}
	return;
}
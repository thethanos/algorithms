#pragma once

#include <iostream>

/*****Depth first traversal (recursion)****
*  Time complexity: O(n)                  *
*  Auxiliary space: O(1)                  *
******************************************/

struct Node
{
	Node(int value) :value(value) {};

	int value = 0;

	Node* left = nullptr;
	Node* right = nullptr;
};


void depth_first_traversal_preorder(Node* node)
{
	if (!node) return;

	//visit current node
	depth_first_traversal_preorder(node->left);
	depth_first_traversal_preorder(node->right);
}

void depth_first_traversal_inorder(Node* node)
{
	if (!node) return;

	depth_first_traversal_inorder(node->left);
	//visit current node
	depth_first_traversal_inorder(node->right);
}

void depth_first_traversal_postorder(Node* node)
{
	if (!node) return;

	depth_first_traversal_postorder(node->left);
	depth_first_traversal_postorder(node->right);
	//visit current node
}
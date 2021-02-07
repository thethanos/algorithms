#pragma once

#include <queue>

using std::queue;

/****Breadth first traversal using queue*****
*  Time complexity: O(n)                    *
*  Auxiliary space: O(n)                    *
*********************************************/

struct Node
{
	Node(int value) :value(value) {}

	int value = 0;

	Node* left = nullptr;
	Node* right = nullptr;
};

void breadth_first_traversal(Node* node)
{
	queue<Node*> que;
	que.push(node);

	Node* cur_node = nullptr;
	while (!que.empty())
	{
		cur_node = que.front();
		que.pop();
		
		if (cur_node)
		{
			//visit current node, then add its children to the queue
			que.push(cur_node->left);
			que.push(cur_node->right);
		}
	}
}
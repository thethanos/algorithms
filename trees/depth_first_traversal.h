#pragma once

#include <stack>

using std::stack;

/*****Depth first traversal using stack****
*  Time complexity: O(n * n)              *
*  Auxiliary space: O(n)                  *
*******************************************/

struct Node
{
	Node(int value) :value(value) {}

	int value = 0;

	Node* left = nullptr;
	Node* right = nullptr;
};

void depth_first_traversal(Node* node)
{
	stack<Node*> st;

	Node* cur_node = node;
	while (!st.empty() || cur_node)
	{
		while (cur_node)
		{
			st.push(cur_node);
			cur_node = cur_node->left;
		}

		cur_node = st.top();
		st.pop();

		//visit current node

		cur_node = cur_node->right;
	}
}
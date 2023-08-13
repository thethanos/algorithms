#pragma once

#include <stack>
#include <vector>

using std::stack;
using std::vector;

/******Depth first traversal using stack******
*  Graph representation: adjacency matrix    *
*  Time complexity: O(V * V)                 *
*  Auxiliary space: O(V)                     *
**********************************************/

void depth_first_traversal(int start, const vector<vector<int>>& graph)
{
	vector<bool> visited(graph.size());

	stack<int> st;
	st.push(start);

	while (!st.empty())
	{
		int cur_vert = st.top();
		st.pop();

		if (!visited[cur_vert]) {
			visited[cur_vert] = true;
		}

		for (int adj_vert(graph.size()-1); adj_vert >= 0; --adj_vert) {
			if (!visited[adj_vert] && graph[cur_vert][adj_vert]) {
				st.push(adj_vert);
			}
		}
	}
}

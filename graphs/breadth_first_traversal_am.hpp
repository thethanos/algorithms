#pragma once

#include <queue>
#include <vector>

using std::vector;
using std::queue;

/****Breadth first traversal using queue******
*  Graph representation: adjacency matrix    *
*  Time complexity: O(V * V)                 *
*  Auxiliary space: O(V)                     *
**********************************************/

void breadth_firts_traversal(int start, const vector<vector<int>>& graph)
{
	vector<bool> visited(graph.size());
	visited[start] = true;

	queue<int> que;
	que.push(start);

	int cur_vert(0);
	while (!que.empty())
	{
		cur_vert = que.front();
		que.pop();

		for (int adj_vert(0); adj_vert < graph.size(); ++adj_vert)
		{
			if (!visited[adj_vert] && graph[cur_vert][adj_vert])
			{
				visited[adj_vert] = true;
				que.push(adj_vert);
			}
		}
	}
}
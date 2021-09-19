#pragma once

#include <vector>

using std::vector;

/*********Detecting cycles (recursion)********
*  Graph representation: adjacency matrix    *
*  Time complexity: O(V * V)                 *
*  Auxiliary space: O(V)                     *
**********************************************/

bool visit_vertex(int cur_vert, int parent, const vector<vector<int>>& graph, vector<bool>& visited);

bool has_cycle(const vector<vector<int>>& graph)
{
	std::vector<bool> visited(graph.size());
	
	for (int cur_vert(0); cur_vert < graph.size(); ++cur_vert)
	{
		if (visited[cur_vert]) continue;

		if (visit_vertex(cur_vert, -1, graph, visited))
		return true;
	}

	return false;
}

bool visit_vertex(int cur_vert, int parent, const vector<vector<int>>& graph, vector<bool>& visited)
{
	visited[cur_vert] = true;

	for (int adj_vert(0); adj_vert < graph.size(); ++adj_vert)
	{
		if (!graph[cur_vert][adj_vert]) continue;

		if (!visited[adj_vert])
		{
			if (visit_vertex(adj_vert, cur_vert, graph, visited))
				return true;
		}
		else if (adj_vert != parent)
			return true;
	}

	return false;
}
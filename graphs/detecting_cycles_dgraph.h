#pragma once

#include <vector>

using std::vector;

/*********Detecting cycles (recursion)********
*  Graph representation: adjacency matrix    *
*  Time complexity: O(V * V)                 *
*  Auxiliary space: O(V)                     *
**********************************************/

bool visit_vertex(int vertex, vector<bool>& visited, vector<bool>& res, const vector<vector<int>>& graph);

bool has_cycle(const vector<vector<int>>& graph)
{
	vector<bool> visited(graph.size());
	vector<bool> res(graph.size());

	for (int vertex(0); vertex < graph.size(); ++vertex)
		if (visit_vertex(vertex, visited, res, graph))
			return true;

	return false;
}

bool visit_vertex(int vertex, vector<bool>& visited, vector<bool>& res, const vector<vector<int>>& graph)
{
	if (!visited[vertex])
	{
		visited[vertex] = true;
		res[vertex] = true;

		for (int adj_vert(0); adj_vert < graph.size(); ++adj_vert)
		{
			if (!graph[vertex][adj_vert]) continue;

			if (!visited[adj_vert])
			{
				if (visit_vertex(adj_vert, visited, res, graph))
					return true;
			}
			else if (res[adj_vert])
				return true;
		}
	}

	res[vertex] = false;
	return false;
}
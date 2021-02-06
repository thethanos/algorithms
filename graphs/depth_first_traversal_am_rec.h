#pragma once

#include <vector>

using std::vector;

/******Depth first traversal (recursion)******
*  Graph representation: adjacency matrix    * 
*  Time complexity: O(V * V)                 *
*  Auxiliary space: O(V)                     *
**********************************************/

void visit_vertex(int cur_vert, vector<vector<int>>& graph, vector<bool>& visited);

void depth_first_traversal(int start, vector<vector<int>>& graph)
{
	vector<bool> visited(graph.size());

	visited[start] = true;

	for (int adj_vert(0); adj_vert < graph.size(); ++adj_vert)
	{
		if (!visited[adj_vert] && graph[start][adj_vert])
			visit_vertex(adj_vert, graph, visited);
	}
}

void visit_vertex(int cur_vert, vector<vector<int>>& graph, vector<bool>& visited)
{
	visited[cur_vert] = true;

	for (int adj_vert(0); adj_vert < graph.size(); ++adj_vert)
	{
		if (!visited[adj_vert] && graph[cur_vert][adj_vert])
			visit_vertex(adj_vert, graph, visited);
	}
}
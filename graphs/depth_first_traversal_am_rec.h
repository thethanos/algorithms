#pragma once

#include <vector>

/******Depth first traversal (recursion)******
*  Graph representation: adjacency matrix    * 
*  Time complexity: O(V + E)                 *
*  Auxiliary space: O(V)                     *
**********************************************/

//C-style

void visit_vertex(int cur_vert, int** graph, size_t size, bool* visited);

void depth_first_traversal(int start, int** graph, size_t size)
{
	bool* visited = new bool[size];
	memset(visited, 0, size);

	visited[start] = true;

	for (int adj_vert(0); adj_vert < size; ++adj_vert)
	{
		if (!visited[adj_vert] && graph[start][adj_vert])
			visit_vertex(adj_vert, graph, size, visited);
	}
}

void visit_vertex(int cur_vert, int** graph, size_t size, bool* visited)
{
	visited[cur_vert] = true;

	for (int adj_vert(0); adj_vert < size; ++adj_vert)
	{
		if (!visited[adj_vert] && graph[cur_vert][adj_vert])
			visit_vertex(adj_vert, graph, size, visited);
	}
}

//STL-style

void visit_vertex(int cur_vert, std::vector<std::vector<int>>& graph, std::vector<bool>& visited);

void depth_first_traversal(int start, std::vector<std::vector<int>>& graph)
{
	std::vector<bool> visited(graph.size());

	visited[start] = true;

	for (int adj_vert(0); adj_vert < graph.size(); ++adj_vert)
	{
		if (!visited[adj_vert] && graph[start][adj_vert])
			visit_vertex(adj_vert, graph, visited);
	}
}

void visit_vertex(int cur_vert, std::vector<std::vector<int>>& graph, std::vector<bool>& visited)
{
	visited[cur_vert] = true;

	for (int adj_vert(0); adj_vert < graph.size(); ++adj_vert)
	{
		if (!visited[adj_vert] && graph[cur_vert][adj_vert])
			visit_vertex(adj_vert, graph, visited);
	}
}
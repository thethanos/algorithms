#pragma once

#include <vector>

using std::vector;

/************Dijkstra's algorithm*************
*  Graph representation: adjacency matrix    *
*  Time complexity: O(V * V)                 *
*  Auxiliary space: O(V)                     *
**********************************************/

int get_next_vertex(const vector<int>& visited, const vector<int>& distances);

vector<int> dijkstra_algorithm(int start, const vector<vector<int>>& graph, vector<int>& path_util)
{
	vector<int> visited(graph.size());
	vector<int> distances(graph.size(), INT32_MAX);
	path_util.resize(graph.size());

	distances[start] = 0;
	path_util[start] = -1;

	for (int i(0); i < graph.size()-1; ++i)
	{
		int cur_vert = get_next_vertex(visited, distances);
		visited[cur_vert] = true;

		for (int adj_vert(0); adj_vert < graph.size(); ++adj_vert)
		{
			if (visited[adj_vert] || !graph[cur_vert][adj_vert]) continue;

			if (distances[cur_vert] + graph[cur_vert][adj_vert] < distances[adj_vert])
			{
				path_util[adj_vert] = cur_vert;
				distances[adj_vert] = distances[cur_vert] + graph[cur_vert][adj_vert];
			}
		}
	}

	return distances;
}

int get_next_vertex(const vector<int>& visited, const vector<int>& distances)
{
	int min_dist(INT32_MAX), min_index(0);

	for (int vertex(0); vertex < distances.size(); ++vertex)
	{
		if (!visited[vertex] && distances[vertex] < min_dist)
		{
			min_dist = distances[vertex];
			min_index = vertex;
		}
	}

	return min_index;
}

void get_shortest_path_util(int cur_vert, vector<int>& path, const vector<int>& path_util);

vector<int> get_shortest_path(int from, int to, const vector<vector<int>>& graph)
{
	vector<int> path, path_util;

	dijkstra_algorithm(from, graph, path_util);
	get_shortest_path_util(to, path, path_util);

	path.push_back(to);
	return path;
}

void get_shortest_path_util(int cur_vert, vector<int>& path, const vector<int>& path_util)
{
	if (path_util[cur_vert] == -1)
		return;

	get_shortest_path_util(path_util[cur_vert], path, path_util);

	path.push_back(path_util[cur_vert]);
}

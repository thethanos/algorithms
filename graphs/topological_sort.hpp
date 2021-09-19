#pragma once

#include <vector>
#include <list>

/********Topological sort (recursion)*********
*  Graph representation: adjacency list      *
*  Time complexity: O(V + E)                 *
*  Auxiliary space: O(V)                     *
**********************************************/

void topological_sort_rec(int cur_vert, const std::vector<std::list<int>>& graph, std::vector<bool>& visited, std::vector<int>& res);

std::vector<int> topological_sort(const std::vector<std::list<int>>& graph)
{
    std::vector<int> res;
    res.reserve(graph.size());

    std::vector<bool> visited(graph.size());

    for (int vertex(0); vertex < graph.size(); ++vertex)
        if (!visited[vertex])
            topological_sort_rec(vertex, graph, visited, res);


    return std::vector<int> {res.rbegin(), res.rend()};
}

void topological_sort_rec(int cur_vert, const std::vector<std::list<int>>& graph, std::vector<bool>& visited, std::vector<int>& res)
{
    visited[cur_vert] = true;

    for (auto adj_vert : graph[cur_vert])
        if (!visited[adj_vert])
            topological_sort_rec(adj_vert, graph, visited, res);

    res.push_back(cur_vert);
}
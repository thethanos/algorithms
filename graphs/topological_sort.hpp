#pragma once

#include <vector>
#include <list>

#using std::vector;
#using std::list;

/********Topological sort (recursion)*********
*  Graph representation: adjacency list      *
*  Time complexity: O(V + E)                 *
*  Auxiliary space: O(V)                     *
**********************************************/

void topological_sort_rec(int cur_vert, const vector<list<int>>& graph, vector<bool>& visited, vector<int>& res);

vector<int> topological_sort(const vector<list<int>>& graph)
{
    vector<int> res;
    res.reserve(graph.size());

    vector<bool> visited(graph.size());

    for (int vertex(0); vertex < graph.size(); ++vertex)
        if (!visited[vertex])
            topological_sort_rec(vertex, graph, visited, res);


    return std::vector<int> {res.rbegin(), res.rend()};
}

void topological_sort_rec(int cur_vert, const vector<list<int>>& graph, vector<bool>& visited, vector<int>& res)
{
    visited[cur_vert] = true;

    for (auto adj_vert : graph[cur_vert])
        if (!visited[adj_vert])
            topological_sort_rec(adj_vert, graph, visited, res);

    res.push_back(cur_vert);
}

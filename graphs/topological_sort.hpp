#pragma once

#include <vector>
#include <list>
#include <forward_list>

using std::vector;
using std::list;
using std::forward_list;

/********Topological sort (recursion)*********
*  Graph representation: adjacency list      *
*  Time complexity: O(V + E)                 *
*  Auxiliary space: O(V)                     *
**********************************************/

void topological_sort_rec(const vector<list<int>>& graph, int cur_vert, vector<bool>& visited, forward_list<int>& res);

forward_list<int> topological_sort(const vector<list<int>>& graph)
{
    vector<bool> visited(graph.size());
    forward_list<int> res;

    for (int vertex(0); vertex < graph.size(); ++vertex)
        if (!visited[vertex])
            topological_sort_rec(graph, vertex, visited, res);

    return res;
}

void topological_sort_rec(const vector<list<int>>& graph, int cur_vert, vector<bool>& visited, forward_list<int>& res)
{
    visited[cur_vert] = true;

    for (auto adj_vert : graph[cur_vert])
        if(!visited[adj_vert])
            topological_sort_rec(graph, adj_vert, visited, res);

    res.push_front(cur_vert);
}

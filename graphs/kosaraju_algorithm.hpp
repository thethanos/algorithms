#pragma once

#include <vector>
#include <list>

using std::vector;
using std::list;

/***********Kosaraju's algorithm**************
*  Graph representation: adjacency list      *
*  Time complexity: O(V + E)                 *
*  Auxiliary space: O(V)                     *
**********************************************/

list<int> dfs(const vector<list<int>>& graph);
void dfs_util(const vector<list<int>>& graph, int cur_vert, vector<bool>& visited, list<int>& res);

vector<list<int>> get_reversed_graph(const vector<list<int>>& graph);

vector<list<int>> kosaraju_algorithm(const vector<list<int>>& graph)
{
    vector<list<int>> res;

    auto dfs_res = dfs(graph);

    auto reversed_graph = get_reversed_graph(graph);

    vector<bool> visited(graph.size());
    for (auto vertex : dfs_res)
    {
        list<int> res_list;
        if (!visited[vertex])
            dfs_util(reversed_graph, vertex, visited, res_list);

        if (!res_list.empty())
            res.push_back(res_list);
    }

    return res;
}

list<int> dfs(const vector<list<int>>& graph)
{
    list<int> res;
    vector<bool> visited(graph.size());

    dfs_util(graph, 0, visited, res);

    return res;   
}

void dfs_util(const vector<list<int>>& graph, int cur_vert, vector<bool>& visited, list<int>& res)
{
    visited[cur_vert] = true;

    for (auto adj_vert : graph[cur_vert])
    {
        if (!visited[adj_vert])
            dfs_util(graph, adj_vert, visited, res);
    }

    res.push_back(cur_vert);
}

vector<list<int>> get_reversed_graph(const vector<list<int>>& graph)
{
    vector<list<int>> res(graph.size());
    for (int vertex(0); vertex < graph.size(); ++vertex)
    {
        for (auto adj_vert : graph[vertex])
            res[adj_vert].push_back(vertex);   
    }

    return res;
}
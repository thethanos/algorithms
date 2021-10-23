#pragma once

#include <vector>
#include <queue>

using std::vector;
using std::queue;

/***********Edmonds-Karp algorithm************
*  Graph representation: adjacency matrix    *
*  Time complexity: O(V * V * V + E)         *
*  Auxiliary space: O(V)                     *
**********************************************/

bool bfs(const vector<vector<int>>& graph, int source, int sink, vector<int>& path);

int edmonds_karp_algorithm(const vector<vector<int>>& graph, int source, int sink)
{
    vector<vector<int>> rGraph(graph);
    vector<int> path(graph.size());

    int max_flow(0);
    while(bfs(rGraph, source, sink, path))
    {
        int path_flow = INT32_MAX;
        
        for (int cur_vert = sink; cur_vert != source; cur_vert = path[cur_vert])
        {
            int parent = path[cur_vert];
            path_flow = std::min(path_flow, rGraph[parent][cur_vert]);
        }

        for (int cur_vert = sink; cur_vert != source; cur_vert = path[cur_vert])
        {
            int parent = path[cur_vert];
            rGraph[parent][cur_vert] -= path_flow;
            rGraph[cur_vert][parent] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

bool bfs(const vector<vector<int>>& graph, int source, int sink, vector<int>& path)
{
    size_t size = graph.size();

    vector<bool> visited(size);
    visited[source] = true;

    queue<int> que;
    que.push(source);

    while(!que.empty())
    {
        int cur_vert = que.front();
        que.pop();

        for (int adj_vert(0); adj_vert < size; ++adj_vert)
        {
            if (!visited[adj_vert] && graph[cur_vert][adj_vert])
            {
                if (adj_vert == sink)
                {
                    path[adj_vert] = cur_vert;
                    return true;
                }

                que.push(adj_vert);
                path[adj_vert]    = cur_vert;
                visited[adj_vert] = true;   
            }
        }
    }

    return false;
}
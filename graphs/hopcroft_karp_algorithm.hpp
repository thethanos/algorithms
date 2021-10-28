#pragma once

#include <stdint-gcc.h>
#include <vector>
#include <list>
#include <queue>

#define NIL 0
#define INF INT32_MAX

using std::vector;
using std::list;
using std::queue;

/**********Hopcroft-Karp algorithm************
*  Graph representation: adjacency list      *
*  Time complexity: O(E* sqrt(V))            *
*  Auxiliary space: O(V)                     *
**********************************************/

bool bfs(const vector<list<int>>& graph, vector<int>& pairsU, vector<int>& pairsV, vector<int>& dist);
bool dfs(const vector<list<int>>& graph, vector<int>& pairsU, vector<int>& pairsV, vector<int>& dist, size_t cur_vert);

size_t hopcroft_karp_algorithm(const vector<list<int>>& graph, size_t countU, size_t countV)
{
    vector<int> pairsU(countU + 1);
    vector<int> pairsV(countV + 1);
    vector<int> dist(countU + 1);

    size_t res(0);
    while(bfs(graph, pairsU, pairsV, dist))
    {
        for (size_t cur_vert(1); cur_vert <= countU; ++cur_vert)
        {
            if (pairsU[cur_vert] == NIL && dfs(graph, pairsU, pairsV, dist, cur_vert))
                res++;
        }
    }

    return res;
}

bool bfs(const vector<list<int>>& graph, vector<int>& pairsU, vector<int>& pairsV, vector<int>& dist)
{
    queue<int> que;
    for (int cur_vert(1); cur_vert <= pairsU.size() - 1; ++cur_vert)
    {
        if (pairsU[cur_vert] == NIL)
        {
            dist[cur_vert] = NIL;
            que.push(cur_vert);
        }
        else
            dist[cur_vert] = INF;
    }

    dist[NIL] = INF;

    while(!que.empty())
    {
        int cur_vert = que.front();
        que.pop();

        if (dist[cur_vert] < dist[NIL])
        {
            for (auto adj_vert : graph[cur_vert])
            {
                if (dist[pairsV[adj_vert]] == INF)
                {
                    dist[pairsV[adj_vert]] = dist[cur_vert] + 1;
                    que.push(pairsV[adj_vert]);
                }
            }
        }
    }

    return dist[NIL] != INF;
}

bool dfs(const vector<list<int>>& graph, vector<int>& pairsU, vector<int>& pairsV, vector<int>& dist, size_t cur_vert)
{
    if (cur_vert != NIL)
    {
        for (auto adj_vert : graph[cur_vert])
        {
            if (dist[pairsV[adj_vert]] == dist[cur_vert] + 1)
            {
                if (dfs(graph, pairsU, pairsV, dist, pairsV[adj_vert]))
                {
                    pairsV[adj_vert] = cur_vert;
                    pairsU[cur_vert] = adj_vert;
                    return true;
                }
            }
        }

        dist[cur_vert] = INF;
        return false;
    }

    return true;
}
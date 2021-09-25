#pragma once

#include <vector>
#include <stdint.h>

using std::vector;

/*************Prim's algorithm****************
*  Graph representation: adjacency matrix    *
*  Time complexity: O(V * V)                 *
*  Auxiliary space: O(V)                     *
**********************************************/

int get_min_dist_index(const vector<int>& distances, const vector<bool>& mstSet);

vector<int> prim_algorithm(const vector<vector<int>>& graph)
{
    int size = graph.size();

    vector<bool> mstSet(size);
    vector<int> distances(size, INT32_MAX);
    vector<int> parents(size);

    parents[0] = -1;
    distances[0] = 0;

    for (int vertex(0); vertex < size - 1; ++vertex)
    {
        int cur_vert = get_min_dist_index(distances, mstSet);
        mstSet[cur_vert] = true;

        for (int adj_vert(0); adj_vert < size; ++adj_vert)
        {
            if (!mstSet[adj_vert] && graph[cur_vert][adj_vert] && graph[cur_vert][adj_vert] < distances[adj_vert])
            {
                distances[adj_vert] = graph[cur_vert][adj_vert];
                parents[adj_vert] = cur_vert;
            }
        }
    }

    return parents;
}

int get_min_dist_index(const vector<int>& distances, const vector<bool>& mstSet)
{
    int min_index(0), min_dist(INT32_MAX);

    for (int vertex(0); vertex < distances.size(); ++vertex)
    {
        if (!mstSet[vertex] && distances[vertex] < min_dist)
        {
            min_dist = distances[vertex];
            min_index = vertex;
        }
    }

    return min_index;
}
#pragma once

#include <vector>
#include <list>

using std::vector;
using std::list;

/****Graph coloring (greedy algorithm)********
*  Graph representation: adjacency list      *
*  Time complexity: O(V * V + E)             *
*  Auxiliary space: O(V)                     *
**********************************************/

int get_next_color(const vector<bool>& colors);

vector<int> graph_coloring(const vector<list<int>>& graph)
{
    size_t size = graph.size();

    vector<int> res(size, -1);
    res[0] = 0;

    vector<bool> available_colors(size);
    for (int vertex(1); vertex < size; ++vertex)
    {
        for (auto adj_vert : graph[vertex])
        {
            if (res[adj_vert] != -1)
                available_colors[res[adj_vert]] = true;
        }

        res[vertex] = get_next_color(available_colors);

        for (auto adj_vert : graph[vertex])
        {
            if (res[adj_vert] != -1)
                available_colors[res[adj_vert]] = false;
        }
    }

    return res;
}

int get_next_color(const vector<bool>& colors)
{
    for (int i(0); i < colors.size(); ++i)
        if (!colors[i])
            return i;

    return -1;
}
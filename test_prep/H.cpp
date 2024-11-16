#include <vector>
#include <iostream>
#include <algorithm>

namespace color
{
    const int WHITE = 0, RED = 1, BLUE = 2;
}

struct node
{
    int name = 0;
    int color = color::WHITE;
    std::vector<node *> hated{};
};

int alternate_color(int color_i)
{
    switch (color_i)
    {
    case (color::RED):
    {
        return color::BLUE;
    }
    case (color::BLUE):
    {
        return color::RED;
    }
    default:
    {
        return color::WHITE;
    }
    }
}

bool DFS(node *nodes, node *current)
{
    auto begin = current->hated.begin(), end = current->hated.end();
    for (auto it = begin; it != end; it++)
    {
        node *target = *it;

        if (target->color == current->color)
            return false;
        if (target->color == color::WHITE)
        {
            target->color = alternate_color(current->color);
            bool res = DFS(nodes, target);
            if (res == false)
                return false;
        }
        else
            continue;
    }
    return true;
}

bool possibleBipartition(int n, const std::vector<std::vector<int>> &dislikes)
{
    node *nodes = new node[n];

    for (int i = 0; i < n; i++)
    {
        nodes[i] = node{.name = i, .color = color::WHITE};
    }

    for (auto it = dislikes.begin(); it != dislikes.end(); it++)
    {
        int a = (*it)[0] - 1, b = (*it)[1] - 1;
        nodes[a].hated.push_back(nodes + b);
        nodes[b].hated.push_back(nodes + a);
    }

    for (unsigned i = 0; i < n; i++)
    {
        if (nodes[i].color == color::WHITE)
        {
            nodes[i].color = color::BLUE;
            bool res = DFS(nodes, nodes + i);
            if (res == false)
            {
                return false;
            }
        }
        else
            continue;
    }

    delete[] nodes;
    return true;
}
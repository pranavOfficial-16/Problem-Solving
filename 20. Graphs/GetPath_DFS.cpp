#include <bits/stdc++.h>
using namespace std;
bool getpath(int **graph, int v, bool *visited, int s, int e, vector<int> &res)
{
    if (s == e)
    {
        res.push_back(s);
        return true;
    }

    visited[s] = true;

    bool ans = false;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && graph[s][i] == 1)
            ans = getpath(graph, v, visited, i, e, res);
        if (ans == true)
        {
            res.push_back(s);
            return true;
        }
    }

    return ans;
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;

    int **graph = new int *[V];

    for (int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    }

    for (int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[V] = false;

    int s, e;
    cin >> s >> e;

    vector<int> res;

    if (getpath(graph, V, visited, s, e, res))
        for (auto i : res)
            cout << i << " ";

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
bool check(int **edges, int n, bool *visited, int v1, int v2)
{
    if (edges[v1][v2] == 1)
        return true;
    visited[v1] = true;
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && edges[v1][i] == 1)
        {
            ans = check(edges, n, visited, i, v2);
        }
        if (ans == true)
            return true;
    }
    return false;
}
int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    int v1, v2;
    cin >> v1 >> v2;
    if (check(edges, n, visited, v1, v2))
        cout << "true";
    else
        cout << "false";
    return 0;
}
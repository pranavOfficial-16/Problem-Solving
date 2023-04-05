#include <bits/stdc++.h>
using namespace std;
void DFS(int **edges, int n)
{
    
}
void BFS(int **edges, int n)
{

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
            edges[i][j] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout << "DFS" << endl;
    DFS(edges, n);
    cout << "BFS" << endl;
    BFS(edges, n);
    return 0;
}
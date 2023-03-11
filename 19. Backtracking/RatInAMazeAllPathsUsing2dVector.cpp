#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &arr, int n, vector<vector<int>> visited, vector<vector<int>> &ans,
           int x, int y){
    // base case
    if (x == n - 1 && y == n - 1)
    {
        vector<int> temp;
        visited[x][y] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp.push_back(visited[i][j]);
            }
        }
        ans.push_back(temp);
        return;
    }
    // Not safe to move conditions
    if (x >= n || x < 0 || y >= n || y < 0 || visited[x][y] == 1 || arr[x][y] == 0)
        return;

    visited[x][y] = 1;

    // 4 movements - D,L,R,U (lexicographically)

    // Down
    solve(arr, n, visited, ans, x + 1, y);

    // Left
    solve(arr, n, visited, ans, x, y - 1);

    // Right
    solve(arr, n, visited, ans, x, y + 1);

    // Up
    solve(arr, n, visited, ans, x - 1, y);

    visited[x][y] = 0;
}
vector<vector<int>> ratInAMaze(vector<vector<int>> arr, int n)
{
    vector<vector<int>> ans;
    if (arr[0][0] == 0)
        return ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    solve(arr, n, visited, ans, 0, 0);
    return ans;
}
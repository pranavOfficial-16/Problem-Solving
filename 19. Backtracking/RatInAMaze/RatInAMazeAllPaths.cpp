#include <bits/stdc++.h>
using namespace std;
void addSolution(vector<vector<int>> &visited, int n, vector<vector<int>> &ans)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(visited[i][j]);
        }
    }
    ans.push_back(temp);
}
void solve(vector<vector<int>> &arr, int n, vector<vector<int>> visited, vector<vector<int>> &ans,
           int x, int y)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        visited[x][y] = 1;
        addSolution(visited, n, ans);
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
    if (arr[0][0] == 0 || arr[n - 1][n - 1] == 0)
        return ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    solve(arr, n, visited, ans, 0, 0);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> ans = ratInAMaze(arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
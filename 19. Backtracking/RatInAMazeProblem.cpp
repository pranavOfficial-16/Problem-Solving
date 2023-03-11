#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &arr, int n, vector<string> &ans,
           vector<vector<int>> &visited, int x, int y, string path)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    // Not safe to move conditions
    if (x >= n || x < 0 || y >= n || y < 0 || visited[x][y] == 1 || arr[x][y] == 0)
        return;

    visited[x][y] = 1;

    // 4 movements - D,L,R,U (lexicographically)

    // Down
    solve(arr, n, ans, visited, x + 1, y, path + 'D');

    // Left
    solve(arr, n, ans, visited, x, y - 1, path + 'L');

    // Right
    solve(arr, n, ans, visited, x, y + 1, path + 'R');

    // Up
    solve(arr, n, ans, visited, x - 1, y, path + 'U');

    visited[x][y] = 0;
}
vector<string> searchMaze(vector<vector<int>> arr, int n)
{
    vector<string> ans;
    if (arr[0][0] == 0)
        return ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";
    solve(arr, n, ans, visited, 0, 0, path);
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
    vector<string> ans;
    ans = searchMaze(arr, n);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
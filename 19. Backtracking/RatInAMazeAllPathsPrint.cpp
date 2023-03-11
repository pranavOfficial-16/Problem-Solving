#include <bits/stdc++.h>
using namespace std;
void printSolution(vector<vector<int>> &solution, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << solution[i][j] << " ";
        }
    }
    cout << endl;
}
void solve(vector<vector<int>> &arr, int n, vector<vector<int>> &solution, int x, int y)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        solution[x][y] = 1;
        printSolution(solution, n);
        return;
    }
    // Not safe to move conditions
    if (x >= n || x < 0 || y >= n || y < 0 || solution[x][y] == 1 || arr[x][y] == 0)
        return;

    solution[x][y] = 1;

    // 4 movements - D,L,R,U (lexicographically)

    // Down
    solve(arr, n, solution, x + 1, y);

    // Left
    solve(arr, n, solution, x, y - 1);

    // Right
    solve(arr, n, solution, x, y + 1);

    // Up
    solve(arr, n, solution, x - 1, y);

    solution[x][y] = 0;
}
void searchMaze(vector<vector<int>> arr, int n)
{
    vector<vector<int>> solution(n, vector<int>(n, 0));
    solve(arr, n, solution, 0, 0);
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
    searchMaze(arr, n);
    return 0;
}
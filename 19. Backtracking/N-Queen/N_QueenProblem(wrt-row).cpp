#include <bits/stdc++.h>
using namespace std;
void addSolution(vector<vector<int>> &board, int n, vector<vector<int>> &ans)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    // check for same column
    while (x >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x--;
    }

    // check for upper left diagonal
    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // check for upper right diagonal
    x = row;
    y = col;
    while (x >=0 && y < n)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y++;
    }
    return true;
}
void solve(int row, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    // base case
    if (row == n)
    {
        addSolution(board, n, ans);
        return;
    }

    // solve 1 case and rest recursion will take care
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(row + 1, ans, board, n);
            board[row][col] = 0; // backtrack
        }
    }
}
vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(0, ans, board, n);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v = nQueens(n);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
bool solve(vector<vector<char>> &board, const string &word, int index,
           int x, int y, vector<vector<int>> &visited, int m, int n)
{
    // Base case
    if (index == word.size())
        return true;

    // Not safe to move conditions
    if (x < 0 || x >= m || y < 0 || y >= n ||
        visited[x][y] == 1 || board[x][y] != word[index])
        return false;

    visited[x][y] = 1;

    // Check all 4 directions
    bool found =
        solve(board, word, index + 1, x + 1, y, visited, m, n) || // Down
        solve(board, word, index + 1, x - 1, y, visited, m, n) || // Up
        solve(board, word, index + 1, x, y + 1, visited, m, n) || // Right
        solve(board, word, index + 1, x, y - 1, visited, m, n);   // Left

    visited[x][y] = 0; // backtrack

    return found;
}

bool exist(vector<vector<char>> &board, const string &word)
{
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (solve(board, word, 0, i, j, visited, m, n))
                return true;
        }
    }
    return false;
}
#include <bits/stdc++.h>
using namespace std;
bool canPlaceWordHorizontally(vector<string> board, string currentWord, int row, int col)
{
    if (board.size() - col < currentWord.size())
        return false;
    for (int j = 0; j < currentWord.size(); j++)
    {
        if (board[row][j] != '-' && board[row][j] != currentWord[j])
            return false;
    }
    return true;
}
vector<bool> placeWordHorizontally(vector<string> board, string currentWord, int row, int col)
{
    vector<bool> visited;
    for (int j = 0; j < currentWord.size(); j++)
    {
        if (board[row][j] == '-')
        {
            board[row][j] = currentWord[j];
            visited[j] = true;
        }
    }
    return visited;
}
void unplaceWordHorizontally(vector<string> board, string currentWord, vector<bool> visited, int row, int col)
{
    for (int j = 0; j < currentWord.size(); j++)
    {
        if (visited[j] == true)
            board[row][j] = '-';
    }
}
bool canPlaceWordVertically(vector<string> board, string currentWord, int row, int col)
{
    if (board.size() - row < currentWord.size())
        return false;
    for (int i = 0; i < currentWord.size(); i++)
    {
        if (board[i][col] != '-' && board[i][col] != currentWord[i])
            return false;
    }
    return true;
}
vector<bool> placeWordVertically(vector<string> board, string currentWord, int row, int col)
{
    vector<bool> visited;
    for (int i = 0; i < currentWord.size(); i++)
    {
        if (board[i][col] == '-')
        {
            board[i][col] = currentWord[i];
            visited[i] = true;
        }
    }
    return visited;
}
void unplaceWordVertically(vector<string> board, string currentWord, vector<bool> visited, int row, int col)
{
    for (int i = 0; i < currentWord.size(); i++)
    {
        if (visited[i] == true)
            board[i][col] = '-';
    }
}
void addSolution(vector<string> board, vector<string> &ans)
{
    for (int i = 0; i < board.size(); i++)
    {
        string s = "";
        for (int j = 0; board.size(); j++)
        {
            s += board[i][j];
        }
        ans.push_back(s);
    }
}
void solve(vector<string> board, vector<string> words, int index, vector<string> &ans)
{
    // base case
    if (index == words.size())
    {
        addSolution(board, ans);
        return;
    }
    string currentWord = words[index];
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == '-' || board[i][j] == currentWord[0])
            {
                // check horizonally
                if (canPlaceWordHorizontally(board, currentWord, i, j))
                {
                    vector<bool> visited = placeWordHorizontally(board, currentWord, i, j);
                    solve(board, words, index + 1, ans);
                    unplaceWordHorizontally(board, currentWord, visited, i, j);
                }

                // check Vertically
                if (canPlaceWordVertically(board, currentWord, i, j))
                {
                    vector<bool> visited = placeWordVertically(board, currentWord, i, j);
                    solve(board, words, index + 1, ans);
                    unplaceWordVertically(board, currentWord, visited, i, j);
                }
            }
        }
    }
}
vector<string> solveCrossword(vector<string> board, vector<string> words)
{
    vector<string> ans;
    int index = 0;
    solve(board, words, index, ans);
    return ans;
}
int main()
{
    int n = 10;
    vector<string> board;
    for (int i = 0; i < n; i++)
    {
        string s = "";
        cin >> s;
        board.push_back(s);
    }
    string wordlist;
    cin >> wordlist;
    vector<string> words;
    string s = "";
    wordlist[wordlist.size()] = ';';
    for (int i = 0; i <= wordlist.size(); i++)
    {
        if (wordlist[i] == ';')
        {
            words.push_back(s);
            s = "";
        }
        else
            s += wordlist[i];
    }
    vector<string> ans = solveCrossword(board, words);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
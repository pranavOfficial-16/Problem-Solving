#include <bits/stdc++.h>
using namespace std;
bool canPlaceWordHorizontally(vector<string> &board, string currentWord, int row, int col)
{
    if (board.size() - col < currentWord.size())
        return false;
    int i = 0;
    int j = col;
    while (i < currentWord.size())
    {
        if (board[row][j] != '-' && board[row][j] != currentWord[i])
            return false;
        i++;
        j++;
    }
    return true;
}
bool canPlaceWordVertically(vector<string> &board, string currentWord, int row, int col)
{
    if (board.size() - row < currentWord.size())
        return false;
    int i = row;
    int j = 0;
    while (j < currentWord.size())
    {
        if (board[i][col] != '-' && board[i][col] != currentWord[j])
            return false;
        i++;
        j++;
    }
    return true;
}
void placeWordHorizontally(vector<string> &board, string currentWord, vector<bool> &visited, int row, int col)
{
    int i = 0;
    int j = col;
    while (i < currentWord.size())
    {
        if (board[row][j] != '+')
        {
            if (board[row][j] == currentWord[i])
                visited[i] = false;
            else
                visited[i] = true;
            board[row][j] = currentWord[i];
        }
        i++;
        j++;
    }
}
void placeWordVertically(vector<string> &board, string currentWord, vector<bool> &visited, int row, int col)
{
    int i = row;
    int j = 0;
    while (j < currentWord.size())
    {
        if (board[i][col] != '+')
        {
            if (board[i][col] == currentWord[j])
                visited[j] = false;
            else
                visited[j] = true;
            board[i][col] = currentWord[j];
        }
        i++;
        j++;
    }
}
void unplaceWordHorizontally(vector<string> &board, string currentWord, vector<bool> &visited, int row, int col)
{
    int i = 0;
    int j = col;
    while (i < currentWord.size())
    {
        if (visited[i] == true)
            board[row][j] = '-';
        i++;
        j++;
    }
}
void unplaceWordVertically(vector<string> &board, string currentWord, vector<bool> &visited, int row, int col)
{
    int i = row;
    int j = 0;
    while (j < currentWord.size())
    {
        if (visited[j] == true)
            board[i][col] = '-';
        i++;
        j++;
    }
}
void printSolution(vector<string> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}
bool solve(vector<string> &board, vector<string> words, int index)
{
    // base case
    if (index == words.size())
    {
        printSolution(board);
        return true;
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == '-' || board[i][j] == words[index][0])
            {
                vector<bool> visited(words.size(), false);

                // check horizonally
                if (canPlaceWordHorizontally(board, words[index], i, j))
                {
                    placeWordHorizontally(board, words[index], visited, i, j);
                    // recursive call
                    bool nextSolution = solve(board, words, index + 1);
                    if (nextSolution)
                        return true;
                    else
                    {
                        // backtrack
                        unplaceWordHorizontally(board, words[index], visited, i, j);
                    }
                }

                // check Vertically
                if (canPlaceWordVertically(board, words[index], i, j))
                {
                    placeWordVertically(board, words[index], visited, i, j);
                    // recursive call
                    bool nextSolution = solve(board, words, index + 1);
                    if (nextSolution)
                        return true;
                    else
                    {
                        // backtrack
                        unplaceWordVertically(board, words[index], visited, i, j);
                    }
                }
            }
        }
    }
    return false;
}
void solveCrossword(vector<string> &board, vector<string> words)
{
    int index = 0;
    bool ans = solve(board, words, index);
}

int main()
{
    int n = 10;
    vector<string> board;
    for (int i = 0; i < n; i++)
    {
        string s;
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
    solveCrossword(board, words);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*
    Optimal
        TC -> O(2n)
        SC -> O(1) 
*/
int celebrity(vector<vector<int>> &mat)
{
    int n = mat.size();
    int top = 0, down = n - 1;
    while (top < down)
    {
        if (mat[top][down] == 1)
            top++;
        else
            down--;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == top)
            continue;
        else if (mat[top][i] == 0 && mat[i][top] == 1)
            continue;
        else
            return -1;
    }
    return top;
}
#include <bits/stdc++.h>
using namespace std;
int removeStones(vector<vector<int>> &stones)
{
    set<int> xcoord, ycoord;
    int n = stones.size();
    for (int i = 0; i < n; i++)
    {
        xcoord.insert(stones[i][0]);
        ycoord.insert(stones[i][1]);
    }
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (xcoord.find(stones[i][0]) != xcoord.end() || ycoord.find(stones[i][1]) != ycoord.end())
        {
            cout << i << count<<endl;
            count++;
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> stones = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
    cout << removeStones(stones);
    return 0;
}
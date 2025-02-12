#include <bits/stdc++.h>
using namespace std;
struct Data
{
    int start;
    int end;
};
static bool comp(Data v1, Data v2)
{
    return v1.end < v2.end;
}
int maxMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();

    vector<Data> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].start = start[i];
        arr[i].end = end[i];
    }

    sort(arr.begin(), arr.end(), comp);
    int count = 1, freetime = arr[0].end;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].start > freetime)
        {
            count++;
            freetime = arr[i].end;
        }
    }
    return count;
}
#include <bits/stdc++.h>
using namespace std;
int kthLargest(int input[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
        pq.push(input[i]);
    while (k - 1 > 0){
        pq.pop();
        k--;
    }
    return pq.top();
}
int main()
{
    int input[] = {9, 4, 8, 7, 11, 3};
    int k = 2;
    cout << kthLargest(input,6,k);
    return 0;
}
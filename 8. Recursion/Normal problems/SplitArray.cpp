/*
check if the input array can be split in two sub-arrays such that:
    Sum of both the sub-arrays is equal.
    All the elements which are divisible by 5 should be in the same group.
    All the elements which are divisible by 3 (but not divisible by 5) should be in the other group.
    Elements which are neither divisible by 5 nor by 3 can be put in any group.
If possible then print true else print false.
*/
/*
Complexity Analysis:
    Time Complexity: O(2 ^ N)
    Auxiliary Space: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
bool solve(int *arr, int n, int start, int lsum, int rsum)
{
    // If reached the end
    if (start == n)
        return lsum == rsum;

    // If divisible by 5 then add to the left sum
    if (arr[start] % 5 == 0)
        lsum += arr[start];

    // If divisible by 3 but not by 5 then add to the right sum
    else if (arr[start] % 3 == 0)
        rsum += arr[start];

    // Else it can be added to any of the sub-arrays
    else
    {
        // Try adding in both the sub-arrays (one by one) and check whether the condition satisfies
        return (
            solve(arr, n, start + 1, lsum + arr[start], rsum) ||
            solve(arr, n, start + 1, lsum, rsum + arr[start]));
    }
    // For cases when element is multiple of 3 or 5.
    return solve(arr, n, start + 1, lsum, rsum);
}
bool splitArray(int *arr, int n)
{
    return solve(arr, n, 0, 0, 0);
}
int main()
{
    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    if (splitArray(input, size))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}

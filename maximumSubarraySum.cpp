/*
         *Largest Sum Contiguous Subarray
    *KADANE'S ALGORITHM:
        Initialize:
        max_so_far = INT_MIN
        max_ending_here = 0

        Loop for each element of the array
            (a) max_ending_here = max_ending_here + a[i]
            (b) if(max_so_far < max_ending_here)
                max_so_far = max_ending_here
            (c) if(max_ending_here < 0)
                max_ending_here = 0
        return max_so_far
*/

#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(int a[], int n)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int res = maxSumSubarray(a, n);
    cout << res;
    return 0;
}
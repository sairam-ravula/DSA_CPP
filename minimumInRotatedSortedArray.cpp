/*
*We can do it in O(Logn) using Binary Search.
*If we take a closer look at the above examples, we can easily figure out the following pattern:

*The minimum element is the only element whose previous is greater than it.
*If there is no previous element, then there is no rotation (the first element is minimum).
*We check this condition for the middle element by comparing it with (mid-1)’th and (mid+1)’th elements.
*If the minimum element is not at the middle (neither mid nor mid + 1), then the minimum element lies in either the left half or right half.
*If the middle element is smaller than the last element, then the minimum element lies in the left half
*Else minimum element lies in the right half.
*/
// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

#include <bits/stdc++.h>
using namespace std;

int minInRotatedSortedArray(vector<int> &v, int n, int low, int high)
{
    int mid = (low + high) / 2;
    if (v[mid] < v[mid - 1])
        return v[mid];
    if (v[mid] > v[n - 1])
        return minInRotatedSortedArray(v, n, mid + 1, high);
    else
        return minInRotatedSortedArray(v, n, 0, mid - 1);
    return -1;
}
int main()
{
    vector<int> v;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    int res = minInRotatedSortedArray(v, n, 0, n - 1);
    cout << res;
    return 0;
}
/*
 *Input: nums = [3,2,1,5,6,4], k = 2
 *Output: 5

 *First Sort the array and return the kth element from the last
 */

#include <bits/stdc++.h>
using namespace std;

int KthLargestElement(vector<int> &v, int n, int k)
{
    sort(v.begin(), v.end());
    return v[n - k];
}

int main()
{
    vector<int> v;
    int n, a, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    cin >> k;
    int res = KthLargestElement(v, n, k);
    cout << res;
    return 0;
}

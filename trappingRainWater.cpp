/*
 *Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 *Output: 6
 *Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 *In this case, 6 units of rain water (blue section) are being trapped.
 */
/*
 *First we pre-compute left_max and right_max arrays and add the min of l_max[i] and r_max[i] with arr[i].
 * we compute left_max array from left and right_max array from right.
 */

#include <bits/stdc++.h>
using namespace std;

int trapWater(vector<int> &arr, int n)
{
    vector<int> lmax(n, 0), rmax(n, 0);
    int res = 0;
    lmax[0] = arr[0];
    for (int i = 1; i <= n - 1; i++)
    {
        lmax[i] = max(lmax[i - 1], arr[i]);
    }
    rmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(rmax[i + 1], arr[i]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        res = res + (min(lmax[i], rmax[i]) - arr[i]);
    }
    return res;
}

int main()
{
    vector<int> v;
    int a, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    int res = trapWater(v, n);
    cout << res;
    return 0;
}
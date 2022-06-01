/*
 *Given an array of n integers where each value represents the number of chocolates in a packet.
 *Each packet can have a variable number of chocolates.
 *There are m students, the task is to distribute chocolate packets such that:
 *   1.Each student gets one packet.
 *   2. The difference between the number of chocolates in the packet with maximum chocolates
 *      and packet with minimum chocolates given to the students is minimum.
 */

#include <bits/stdc++.h>
using namespace std;

int chocolateDistributed(vector<int> &arr, int m, int n)
{
    int min_diff = INT_MAX;
    sort(arr.begin(), arr.end());
    if (m > n)
    {
        return -1;
    }
    for (int i = 0; i + m - 1 < n; i++) // use for loop upto i+m-1 < n
    {
        min_diff = min(min_diff, arr[i + m - 1] - arr[i]);
    }
    return min_diff;
}

int main()
{
    int m, a, n;
    vector<int> v;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    int res = chocolateDistributed(v, m, n);
    cout << res;
    return 0;
}
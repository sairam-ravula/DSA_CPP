/*
 * We use binary search to search for an element
 * find mid element and if it matches with key element then return mid
 *
 * 1) Find middle point mid = (l + h)/2
 * 2) If key is present at middle point, return mid.
 * 3) Else If arr[l..mid] is sorted
 *    a) If key to be searched lies in range from arr[l]
 *      to arr[mid], recur for arr[l..mid].
 *    b) Else recur for arr[mid+1..h]
 * 4) Else (arr[mid+1..h] must be sorted)
 *    a) If key to be searched lies in range from arr[mid+1]
 *      to arr[h], recur for arr[mid+1..h].
 *   b) Else recur for arr[l..mid]
 */

#include <bits/stdc++.h>
using namespace std;

int searchinRotatedSorted(vector<int> &v, int target, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (v[mid] == target)
        return mid;
    if (v[mid] >= v[low])
    {
        if (v[mid] >= target && v[low] <= target)
            return searchinRotatedSorted(v, target, low, mid - 1);
        return searchinRotatedSorted(v, target, mid + 1, high);
    }
    if (v[mid] <= target && v[high] >= target)
        return searchinRotatedSorted(v, target, mid + 1, high);
    return searchinRotatedSorted(v, target, low, mid - 1);
}
int main()
{
    vector<int> v;
    int n, a, target;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    cin >> target;
    int res = searchinRotatedSorted(v, target, 0, n - 1);
    cout << "Element found at index : " << res;
    return 0;
}
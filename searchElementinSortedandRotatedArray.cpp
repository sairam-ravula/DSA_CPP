/*
 *Approach: Instead of two or more pass of binary search the result can be found in one pass of binary search.
 *The binary search needs to be modified to perform the search.
 *The idea is to create a recursive function that takes l and r as range in input and the key.
 */
// 1) Find middle point mid = (l + h)/2
// 2) If key is present at middle point, return mid.
// 3) Else If arr[l..mid] is sorted
//     a) If key to be searched lies in range from arr[l]
//        to arr[mid], recur for arr[l..mid].
//     b) Else recur for arr[mid+1..h]
// 4) Else (arr[mid+1..h] must be sorted)
//     a) If key to be searched lies in range from arr[mid+1]
//        to arr[h], recur for arr[mid+1..h].
//     b) Else recur for arr[l..mid]

/*
 *Time complexity : O(log n)
 *Space complexity : O(1), no extra space is required
 */

#include <bits/stdc++.h>
using namespace std;

int searchElement(vector<int> &a, int l, int h, int key)
{
    if (l > h)
    {
        return -1;
    }
    int mid = (l + h) / 2;
    if (a[mid] == key)
    {
        return mid;
    }
    if (a[l] < a[mid])
    {
        if (key >= a[l] && key <= a[mid])
        {
            return searchElement(a, l, mid - 1, key);
        }
        return searchElement(a, mid + 1, h, key);
    }
    if (key >= a[mid + 1] && key <= a[h])
    {
        return searchElement(a, mid + 1, h, key);
    }
    return searchElement(a, l, mid - 1, key);
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
    int key;
    cin >> key;
    int res = searchElement(v, 0, v.size() - 1, key);
    (res != -1) ? cout << "Key found at index : " << res : cout << "Key not found";
    return 0;
}
/*
 *A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
 *For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
 *The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
 *More formally, if all the permutations of the array are sorted in one container according to their lexicographical order,
 *then the next permutation of that array is the permutation that follows it in the sorted container.
 *If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
 */
/*
!Approach
*->First we swap the peak element with less weightage (greater element from right side) with its next smallest element on its left.
*->Later we sort the elements after the first swap position in ascending order.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &arr, int n)
{
    int peakIndex = -1, i = 1;
    if (n == 1)
        return arr;
    while (i < n) // get the peak element index
    {
        if (arr[i] > arr[i - 1])
            peakIndex = i;
        i++;
    }
    if (peakIndex == -1) // if the elements are in descending order, sort them
    {
        sort(arr.begin(), arr.end());
        return arr;
    }
    int index = peakIndex;
    for (i = peakIndex; i < n; i++) // exceptional case where there is another peak element on the rightmost side
    {
        if ((arr[peakIndex - 1] < arr[i]) && (arr[i] < arr[peakIndex]))
            index = i;
    }
    swap(arr[peakIndex - 1], arr[index]);     // swap peak element with its next smaller element
    sort(arr.begin() + peakIndex, arr.end()); // sort the array from first swapped position to its right
    return arr;
}

int main()
{
    int n, a, i = 0;
    vector<int> arr;
    cin >> n;
    while (i < n)
    {
        cin >> a;
        arr.push_back(a);
        i++;
    }
    vector<int> res = nextPermutation(arr, n);
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}
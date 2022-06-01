/*
 * This program will show how to reverse an array
 */

#include <bits/stdc++.h>
using namespace std;

// initialize start and end as 0 and n-1 respectively
// swap the array elements at start and end indices until start is greater than end
// Here I swapped the two variables without using third variable(extra space)

void reverse(int arr[], int n)
{
    int start = 0, end = n - 1, temp;
    while (start < end)
    {
        // temp = arr[start];
        // arr[start] = arr[end];
        // arr[end] = temp;

        // method 1:
        arr[start] = arr[start] + arr[end];
        arr[end] = arr[start] - arr[end];
        arr[start] = arr[start] - arr[end];

        // method 2:
        // arr[start] = arr[start] ^ arr[end];
        // arr[end] = arr[start] ^ arr[end];
        // arr[start] = arr[start] ^ arr[end];
        start++;
        end--;
    }
}

int main()
{
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
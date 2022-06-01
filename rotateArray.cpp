/*
 * This program will show how to rotate an array without any extra space
 * ROTATE ARRAY ONE BY ONE
 */

#include <bits/stdc++.h>
using namespace std;

// Left rotate an array by d steps
//  store first element in temporary variable and left shift all the elements one by one and
// replace last element with temporary variable
void leftrotateArray(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

// right rotate an array by d steps
//  store last element in temporary variable and right shift all the elements one by one and
// replace first element with temporary variable
void rightrotateArray(int arr[], int n)
{
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

int main()
{
    int n, d;
    int arr[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    cin >> d;
    int d1 = d;
    while (d > 0)
    {
        leftrotateArray(arr, n);
        d--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    while (d1 > 0)
    {
        rightrotateArray(arr, n);
        d1--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
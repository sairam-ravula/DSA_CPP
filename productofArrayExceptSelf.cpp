/*
*Algorithm:

*1. Create an array product and initialize its value to 1 and a variable temp = 1.
*2. Traverse the array from start to end.
*3. For every index i update product[i] as product[i] = temp and temp = temp * array[i],
*i.e store the product upto i-1 index from the start of array.
*4. initialize temp = 1 and traverse the array from last index to start.
*5. For every index i update product[i] as product[i] = product[i] * temp and temp = temp * array[i],
*i.e multiply with the product upto i+1 index from the end of array.
*6. Print the product array.
*/

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

#include <bits/stdc++.h>
using namespace std;

vector<int> productArray(vector<int> &v, int n)
{
    vector<int> prodArray(n, 1);
    int temp = 1;
    for (int i = 0; i < n; i++)
    {
        prodArray[i] = temp;
        temp *= v[i];
    }
    temp = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        prodArray[i] *= temp;
        temp *= v[i];
    }
    return prodArray;
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
    vector<int> res = productArray(v, n);
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}
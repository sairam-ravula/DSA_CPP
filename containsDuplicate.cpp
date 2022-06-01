/*
 *This program will show whether the array contains any duplicate elements
 * If duplicates are present return true else return false
 */

#include <bits/stdc++.h>
using namespace std;

bool containDuplicates(vector<int> &arr)
{
    map<int, int> duplicates;
    for (auto i : arr)
    {
        if (duplicates[i])
        {
            return true;
        }
        else
        {
            duplicates[i]++;
        }
    }
    return false;
}

int main()
{
    vector<int> v1;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v1.push_back(a);
    }
    bool res = containDuplicates(v1);
    res ? cout << "true" : cout << "false";
    return 0;
}
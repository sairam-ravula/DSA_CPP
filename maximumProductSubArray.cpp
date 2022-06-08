/*
 * Maintain current_max_product , previous_max_product,
 * current_min_product, previous_min_product
 * current_max_product = max(arr[i]*prev_max_product, arr[i]*prev_min_product, arr[i])
 * current_min_product = min(arr[i]*prev_max_product, arr[i]*prev_min_product, arr[i])
 */
/*
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

#include <bits/stdc++.h>
using namespace std;

int maxproductSubarray(vector<int> &v, int n)
{
    int curr_max_product = v[0], prev_max_product = v[0],
        curr_min_product = v[0], res = v[0];
    for (int i = 1; i < n; i++)
    {
        prev_max_product = max({curr_max_product * v[i], curr_min_product * v[i], v[i]});
        curr_min_product = min({curr_max_product * v[i], curr_min_product * v[i], v[i]});
        curr_max_product = prev_max_product;
        res = max(res, curr_max_product);
    }
    return res;
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
    int res = maxproductSubarray(v, n);
    cout << res;
    return 0;
}
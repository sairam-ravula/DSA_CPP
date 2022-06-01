/*
*Given an array price[] of length N, representing the prices of the stocks on different days,
*the task is to find the maximum profit possible for buying and selling the stocks on different days
*using transactions where at most one transaction is allowed.

*Note: Stock must be bought before being sold.
*/
/*
 *Input: prices[] = {7, 1, 5, 3, 6, 4]
 *Output: 5
 *Explanation:
 *The lowest price of the stock is on the 2nd day, i.e. price = 1. Starting from the 2nd day,
 *the highest price of the stock is witnessed on the 5th day, i.e. price = 6.
 *Therefore, maximum possible profit = 6 – 1 = 5.
 */

/*
!Approach:
*This problem can be solved using greedy approach.
*To maximise the profit we have to minimise the buy cost and we have to sell it on maximum price.
*Follow the steps below to implement the above idea:

*1. Declare a buy variable to store the buy cost and max_profit to store the maximum profit.
*2. Initialize the buy variable to first element of profit array.
*3. Iterate over the prices array and check if the current price is miminum or not.
*4. If the current price is minimum then buy on this ith day.
*5. If the current price is greater then previous buy then make profit from it and maximise the max_profit.
*6. Finally return the max_profit.
*/

#include <bits/stdc++.h>
using namespace std;

int BuyandSellStock(vector<int> &arr, int n)
{
    int max_profit = 0, buy = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < buy)
        {
            buy = arr[i];
        }
        else
            max_profit = max(max_profit, arr[i] - buy);
    }
    return max_profit;
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
    int res = BuyandSellStock(v, n);
    cout << res;
    return 0;
}
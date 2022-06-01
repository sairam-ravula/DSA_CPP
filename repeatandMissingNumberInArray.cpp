// Using Maths

/*
*Now since the numbers are from 1 to N in the array arr[].
Let’s calculate sum of all integers from 1 to N and sum of squares of all integers from 1 to N.
These can easily be done using mathematical formulae.

Therefore,

Sum of all elements from 1 to N:

S = N*(N+1)/2 ---- equation 1
And, Sum of squares of all elements from 1 to N:

P = N(N+1)(2N+1)/6. ----- equation 2
Similarly, find the sum of all elements of the array and sum of squares of all elements of the array respectively.

s1 = Sum of all elements of the array. —– equation 3
P1 = Sum of squares of all elements of the array. ——– equation 4
Now, if we subtract the sum of all elements of array from sum of all elements from 1 to N, that should give us the value for (X – Y).

Therefore,

(X-Y) = s – s1 = s’

Similarily,

X^2 – Y^2 = P – P1 = P’

or, (X + Y)(X – Y) = P’

or, (X + Y)*s’ = P’

or, X + Y = P’/s’

Great,

we have the two equations we needed:

(X – Y) = s’

(X + Y) = P’/s’

We can use the two equations to solve and find values for X and Y respectively.

Note: here s and P can be large so take long long int data type.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> MissingandRepeatingElement(vector<int> arr, int n)
{
    vector<int> ans;
    int x, y;
    long long int S = (n * (n + 1)) / 2;
    long long int P = (n * (n + 1) * (2 * n + 1)) / 6;
    long long int S1 = 0, P1 = 0;
    for (int i = 0; i < n; i++)
    {
        S1 = S1 + (long long int)arr[i];
        P1 = P1 + (long long int)(arr[i] * arr[i]);
    }
    S1 = S1 - S;
    P1 = P1 - P;
    x = (int)((P1 / S1) + S1) / 2;
    y = (int)(x - S1);
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}

int main()
{
    int n, a;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    vector<int> res = MissingandRepeatingElement(v, n);
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}
/*
 * This program will check whether a sentence is valid palindrome or not

 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing
 * all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include
 * letters and numbers.

 * Given a string s, return true if it is a palindrome, or false otherwise.
 */

//* Input: s = "A man, a plan, a canal: Panama"
//* Output: true
//* Explanation: "amanaplanacanalpanama" is a palindrome.

#include <bits/stdc++.h>
using namespace std;

bool validPalindrome(string str)
{
    int st = 0, en = str.length() - 1, flag = 0;
    while (st < en)
    {
        while ((st < en) && (!isalnum(str[st])))
            st++;
        while ((st < en) && (!isalnum(str[en])))
            en--;
        if (tolower(str[st]) == tolower(str[en]))
        {
            flag = 1;
            st++;
            en--;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag)
        return true;
    else
        return false;
}
int main()
{
    string str;
    getline(cin, str);
    bool res = validPalindrome(str);
    cout << res;
    return 0;
}
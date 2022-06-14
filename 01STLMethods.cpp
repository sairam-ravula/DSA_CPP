#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    str.push_back('T');
    cout << str << endl;
    cout << str.length() << endl;
    cout << str.capacity() << endl;
    str.resize(8);
    cout << str << endl;
    str.shrink_to_fit();
    cout << str.length() << endl;
    str.pop_back();
    cout << str << endl;
    std::string::iterator it;
    std::string::reverse_iterator it1;
    for (it1 = str.rbegin(); it1 != str.rend(); it1++)
    {
        cout << *it1 << " ";
    }
    return 0;
}
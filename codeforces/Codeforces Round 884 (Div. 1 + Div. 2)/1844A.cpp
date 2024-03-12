#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    int n, k;
    cin >> n >> k;
    cin >> a;
    vector<int> len;
    int l = 1;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] != a[i - 1])
            len.push_back(l), l = 1;
        else
            l++;
    }
    len.push_back(l);
    // cout<<len.size()<<endl;
    if (a == "1010" || a == "0101")
        cout << "Bob" << endl;
    else if (len.size() == 1)
    {
        if (n <= k)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    else if (len.size() == 2)
    {
        if (*min_element(len.begin(), len.end()) <= k)
            cout << "Alice" << endl;
        else if (a == "1100" || a == "0011")
            cout << "Bob" << endl;
        else
            cout << ":(" << endl;
    }
    else if (len.size() == 3)
    {
        if (len[1] <= k)
            cout << "Alice" << endl;
        else if (a == "1001" || a == "0110")
            cout << "Bob" << endl;
        else
            cout << ":(" << endl;
    }
    else
        cout << ":(";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    int n = str.size();
    str = " " + str;
    int ans = 0, tem = 1, an = 0;
    for (int i = n; i; i--)
    {
        if (str[i] == '1')
            an = (an + tem) % M;
        else if (str[i] == '6')
            ans = (ans + an) % M;
        tem = (2ll * tem) % M;
    }
    cout << ((tem - ans - 1) % M + M) % M;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
bool op(char a, char b)
{
    return a == b;
}
vector<int> prefix_function(string s) // 计算前缀函数
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && !op(s[i], s[j]))
            j = pi[j - 1];
        if (op(s[i], s[j]))
            j++;
        pi[i] = j;
    }
    return pi;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin >> a;
    int n = a.size();
    vector<int> dp(n + 1, 0x3f3f3f3f);
    dp[0] = 0;
    vector<string> from(n + 1, "");
    auto get = [&](int len, string a) {
        if (len == 1)
            return a;
        string ans = to_string(len) + "(" + a.substr(0, a.size() / len) + ")";
        return ans;
    };
    auto big = [&](string a, string b) {
        if (b == "")
            return true;
        if (a.size() < b.size())
            return true;
        if (a.size() == b.size() && a > b)
            return true;
        return false;
    };
    for (int i = 1; i <= n; i++)
    {
        string tem = a.substr(0, i);
        reverse(tem.begin(), tem.end());
        auto p = prefix_function(tem);
        for (int j = 0; j < i; j++)
        {
            int u = p[j];
            while (1)
            {

                if ((j + 1) % (j + 1 - u) == 0)
                {
                    string make = get((j + 1) / (j + 1 - u), a.substr(i - j - 1, j + 1));
                    make = from[i - j - 1] + make;
                    if (big(make, from[i]))
                        from[i] = make;
                }
                if (u == 0)
                    break;
                u = p[u - 1];
            }
        }
    }
    cout << from[n] << endl;
    return 0;
}
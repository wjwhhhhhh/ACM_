#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
void Manacher(vector<int> &d1, vector<int> &d2,
              string s) // 二者也表示了以位置 i 为中心的最长回文串的半径长度（半径长度 d_1[i]，d_2[i] 均为从位置 i
                        // 到回文串最右端位置包含的字符个数）。
{
    auto cmp = [&](char a, char b) {
        if (a == '0' || a == '8')
            return a == b;
        else
        {
            if (a == '9')
                a = '6';
            else if (a == '6')
                a = '9';
            return a == b;
        }
    };
    int n = s.size();
    d1.resize(n), d2.resize(n);
    fill(d1.begin(), d1.end(), 0), fill(d2.begin(), d2.end(), 0);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && cmp(s[i - k], s[i + k]))
        {
            k++;
        }
        d1[i] = k--;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && cmp(s[i - k - 1], s[i + k]))
        {
            k++;
        }
        d2[i] = k--;
        if (i + k > r)
        {
            l = i - k - 1;
            r = i + k;
        }
    }
}
void solve()
{
    string a, b;
    cin >> a;
    vector<int> d1, d2;
    Manacher(d1, d2, a);
    int n = a.size();
    i64 ans = 1ll * n * (n + 1) / 2;
    bool fl = false;
    for (int i = 0; i < n; i++)
        cout << d1[i] << endl;
    for (int i = 0; i < n; i++)
        if (d1[i] || d2[i])
            fl = true;
    for (int i = 0; i < n; i++)
        ans -= d1[i], ans -= d2[i];
    cout << ans + fl << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
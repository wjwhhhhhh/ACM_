#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void Manacher(vector<int> &d1, vector<int> &d2,
              string &s) // 二者也表示了以位置 i 为中心的最长回文串的半径长度（半径长度 d_1[i]，d_2[i] 均为从位置 i
                         // 到回文串最右端位置包含的字符个数）。
{
    int n = s.size();
    d1.resize(n), d2.resize(n);
    fill(d1.begin(), d1.end(), 0), fill(d2.begin(), d2.end(), 0);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
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
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
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
    string a;
    cin >> a;
    int n = a.size();
    string ans = "";
    int len = 0;
    for (int i = 0, j = n - 1; i <= j && a[i] == a[j]; i++, j--)
        len++;
    if (len * 2 >= n)
    {
        cout << a << endl;
        return;
    }
    string b = a.substr(len, n - 2 * len);
    int m = b.size();
    vector<int> d1(m), d2(m);
    Manacher(d1, d2, b);
    int le = 0, ri = 0;
    for (int i = 0; i < m; i++)
    {
        if (i - d1[i] + 1 == 0)
            le = max(le, 2 * d1[i] - 1);
        if (i + d1[i] - 1 == m - 1)
            ri = max(ri, 2 * d1[i] - 1);
        if (i - d2[i] == 0)
            le = max(le, 2 * d2[i]);
        if (i + d2[i] - 1 == m - 1)
            ri = max(ri, 2 * d2[i]);
    }
    if (le >= ri)
    {
        for (int i = 0; i < len; i++)
            cout << a[i];
        for (int i = len; i < len + le; i++)
            cout << a[i];
        for (int i = n - len; i < n; i++)
            cout << a[i];
    }
    else
    {
        // cout << ri << endl;
        for (int i = 0; i < len; i++)
            cout << a[i];
        for (int i = n - len - ri; i < n - len; i++)
            cout << a[i];
        for (int i = n - len; i < n; i++)
            cout << a[i];
    }
    cout << endl;
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
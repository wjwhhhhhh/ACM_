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
struct SA // 最长公共前缀 //会帮你在最后加一个0
{
    vector<int> sa, rk, he;
    string s;
    SA()
    {
    }
    void work()
    {
        s += char(0);
        int n = s.size(), m = 128;
        sa.resize(n), rk.resize(n), he.resize(n);
        vector<int> oldrk(n), key1(n), cnt(max(m, n));
        auto cmp = [&](int a, int b, int l) { return oldrk[a] == oldrk[b] && oldrk[a + l] == oldrk[b + l]; };
        fill(cnt.begin(), cnt.begin() + m, 0);
        for (int i = 0; i < s.size(); i++)
            rk[i] = s[i];
        for (int i = 0; i < n; i++)
            cnt[rk[i]]++;
        for (int i = 1; i < m; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            sa[--cnt[rk[i]]] = i;
        for (int j = 1, p = 1; p < n; j *= 2, m = p)
        {
            p = 0;
            for (int i = n - j; i < n; i++)
                oldrk[p++] = i;
            for (int i = 0; i < n; i++)
                if (sa[i] >= j)
                    oldrk[p++] = sa[i] - j;
            fill(cnt.begin(), cnt.begin() + m, 0);
            for (int i = 0; i < n; i++)
                key1[i] = rk[oldrk[i]];
            for (int i = 0; i < n; i++)
                cnt[key1[i]]++;
            for (int i = 1; i < m; i++)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--)
                sa[--cnt[key1[i]]] = oldrk[i];
            swap(oldrk, rk);
            p = 1, rk[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                rk[sa[i]] = cmp(sa[i - 1], sa[i], j) ? p - 1 : p++;
        }
        for (int i = 0; i < n; i++)
            rk[sa[i]] = i;
        for (int i = 0, k = 0; i < n - 1; i++)
        {
            if (k)
                k--;
            while (s[i + k] == s[sa[rk[i] - 1] + k])
                k++;
            he[rk[i]] = k;
        }
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string a, b;
    cin >> a >> b;

    return 0;
}
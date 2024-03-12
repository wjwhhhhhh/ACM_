#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
const int M = 1e9 + 7;
struct PAM
{
    int sz, tot, last;
    vector<int> cnt, len, fail; // 最长回文子串的回文后缀
    vector<array<int, 26>> ch;
    vector<char> s;
    vector<int> diff, slink, dp, g;
    PAM()
    {
    }
    PAM(int n) // 开大点
    {
        init(n + 2);
    }
    int node(int l)
    {
        sz++;
        fill(ch[sz].begin(), ch[sz].end(), 0);
        len[sz] = l;
        fail[sz] = cnt[sz] = 0;
        return sz;
    }
    void init(int n)
    {
        cnt.resize(n), len.resize(n), fail.resize(n);
        ch.resize(n), s.resize(n);
        diff.resize(n), slink.resize(n);
        dp.resize(n), g.resize(n);
        dp[0] = 1;
        clear();
    }
    void clear()
    {
        sz = -1, last = 0;
        s[tot = 0] = '$';
        node(0);
        node(-1);
        fail[0] = 1;
    }
    int getfail(int x)
    {
        while (s[tot - len[x] - 1] != s[tot])
            x = fail[x];
        return x;
    }
    void insert(char c)
    {
        s[++tot] = c;
        int now = getfail(last);
        if (!ch[now][c - 'a'])
        {
            int x = node(len[now] + 2);
            fail[x] = ch[getfail(fail[now])][c - 'a'];
            ch[now][c - 'a'] = x;
            diff[x] = len[x] - len[fail[x]];
            if (diff[x] == diff[fail[x]])
            {
                slink[x] = slink[fail[x]];
            }
            else
                slink[x] = fail[x];
        }
        last = ch[now][c - 'a'];
        cnt[last]++;
        for (int x = last; x > 1; x = slink[x])
        {
            g[x] = dp[tot - (len[slink[x]] + diff[x])];
            if (diff[x] == diff[fail[x]])
            {
                g[x] = (g[x] + g[fail[x]]) % M;
            }
            if (tot % 2 == 0)
            {
                dp[tot] = (dp[tot] + g[x]) % M;
            }
        }
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string a;
    cin >> a;
    int n = a.size();
    string b;
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        b += a[i], b += a[j];
    }
    PAM pa(n);
    for (int i = 0; i < n; i++)
    {
        pa.insert(b[i]);
    }
    cout << pa.dp[pa.tot] << endl;
    return 0;
}
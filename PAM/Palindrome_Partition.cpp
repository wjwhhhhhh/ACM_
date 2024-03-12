#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct PAM
{
    static int M;
    int sz, tot, last;
    vector<int> cnt, len, fail; // 最长回文子串的回文后缀
    vector<array<int, 26>> ch;
    vector<char> s;
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
        clear();
    }
    void clear()
    {
        sz = -1, last = 0;
        s[tot = 0] = '$';
        node(0);
        cnt[sz] = 0x3f3f3f3f;
        node(-1);
        cnt[sz] = 0x3f3f3f3f;
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
            if (len[x] % 2 == 0)
                cnt[x] = min(len[x], cnt[fail[x]]);
            else
                cnt[x] = cnt[fail[x]];
            ch[now][c - 'a'] = x;
        }
        last = ch[now][c - 'a'];
    }
};
const int N = 5e5 + 10;
void solve()
{
    int n;
    cin >> n;
    PAM pa(n + 100);
    string a;
    cin >> a;
    vector<i64> dp(n + 1);
    a = " " + a;
    for (int i = 1; i <= n; i++)
    {
        pa.insert(a[i]);
        int len = pa.cnt[pa.last];
        // cerr << pa.last << endl;
        if (len == 0x3f3f3f3f)
            dp[i] = 0;
        else
            dp[i] = dp[i - len] + 1;
    }
    i64 ans = 0;
    for (int i = 1; i <= n; i++)
        ans += dp[i];
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
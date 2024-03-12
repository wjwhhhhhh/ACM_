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
int ans = 0;
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
        if (!ch[now][c - 'A'])
        {
            int x = node(len[now] + 2);
            fail[x] = ch[getfail(fail[now])][c - 'A'];
            ch[now][c - 'A'] = x;
        }
        last = ch[now][c - 'A'];
        chkmax(ans, len[last]);
        cnt[last]++;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string a;
    cin >> a;
    PAM pa(a.size() + 10);
    for (int i = 0; i < a.size(); i++)
        pa.insert(a[i]);
    cout << ans << endl;
    return 0;
}
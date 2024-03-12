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
            cnt[x]=cnt[fail[x]]+1;
        }
        last = ch[now][c - 'a'];
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n,q;
    cin>>n>>q;
    PAM pam(n);
    string a;
    cin>>a;
    vector<int> dp(n+1);
    for(int i=0;i<n;i++)
    {
        pam.insert(a[i]);
        dp[i+1]=dp[i-1]+pam.cnt[pam.last];
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        
    }
    return 0;
}
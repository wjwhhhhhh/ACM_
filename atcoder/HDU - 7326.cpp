#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
struct string_hash
{
#define ll long long

    ll Q = 143, M = 1e9 + 7;
    vector<ll> h, p;
    string_hash()
    {
    }
    string_hash(int n)
    {

        init(n);
    }
    void init(int n, ll q = 13131, ll m = 1e9 + 7)
    {
        Q = q, M = m;
        p.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++)
            p[i] = p[i - 1] * Q % M;
        h.push_back(0);
    }
    template <class T> void Prefix_sum_Storage(T &str) // 预处理前缀和
    {
        for (int i = 0; i < str.size(); i++)
        {
            h.push_back((h.back() * Q + str[i]) % M);
        }
    }
    ll get(int l, int r) // 通过前缀和获得字串
    {
        return (h[r] - h[l - 1] * p[r - l + 1] % M + M) % M;
    }
    template <class T>
    void push_back(T c)
    {
         h.push_back(((h.size()?h.back():0) * Q + c) % M);
    }
    void pop_back()
    {
        h.pop_back();
    }
    ll encode(string &str) // 编码
    {
        ll res = 0;
        for (auto i : str)
        {
            res = (res * Q % M + i) % M;
        }
        return res;
    }
};
struct PAM
{
    static int M;
    int sz, tot, last;
    vector<int> cnt, len, fail;//最长回文子串的回文后缀
    vector<array<int, 26>> ch;
    vector<char> s;
    string_hash ha,hb;
    set<pair<ll,ll>> has;
    PAM()
    {
    }
    PAM(int n) // 开大点
    {
        init(n+2);
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
        ha.init(n),hb.init(n,131,1e9+7);
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
        ha.push_back(c);
        hb.push_back(c);
        s[++tot] = c;
        int now = getfail(last);
        if (!ch[now][c - 'a'])
        {
            int x = node(len[now] + 2);
            fail[x] = ch[getfail(fail[now])][c - 'a'];
            ch[now][c - 'a'] = x;
        }
        last = ch[now][c - 'a'];
        has.insert({ha.get(tot-len[last]+1,tot),hb.get(tot-len[last]+1,tot)});
        cnt[last]=cnt[fail[last]];
        if(len[last]%2==0)
        {
            int l=len[last]/2;
            if(has.find({ha.get(tot-l+1,tot),hb.get(tot-l+1,tot)})!=has.end())
            cnt[last]++;
        }
    }
};
void solve()
{
    string a;
    cin>>a;
    int n=a.size();
    i64 res=0;
    PAM pa(n);
    for(int i=0;i<n;i++)
    {
        pa.insert(a[i]);
        res+=pa.cnt[pa.last];
    }
    cout<<res<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
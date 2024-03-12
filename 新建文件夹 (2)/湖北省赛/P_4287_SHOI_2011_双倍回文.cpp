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
    void init(int n, ll q = 131, ll m = 1e9 + 7)
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
    template <class T> void push_back(T c)
    {
        h.push_back(((h.size() ? h.back() : 0) * Q + c) % M);
    }
    void pop_back()
    {
        h.pop_back();
    }
    void clear()
    {
        h.clear();
        h.push_back(0);
    }
    int size()
    {
        return h.size() - 1;
    }
    bool operator<(string_hash a)
    {
        if (this->size() < a.size())
            return true;
        if (this->size() < a.size())
            return false;
        for (int i = 0; i < this->size(); i++)
        {
            if (this->get(i, i) != a.get(i, i))
            {
                if (this->get(i, i) < a.get(i, i))
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
    void operator=(string_hash tem)
    {
        this->h = tem.h;
    };
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
    int sz, tot, last, ans;
    vector<int> cnt, len, fail, val; // 最长回文子串的回文后缀
    vector<array<int, 26>> ch;
    vector<char> s;
    string_hash ha;
    PAM()
    {
    }
    PAM(int n) // 开大点
    {
        ans = 0;
        ha.init(n);
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
        val.resize(n);
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
        ha.push_back(c);
        int now = getfail(last);
        if (!ch[now][c - 'a'])
        {
            int x = node(len[now] + 2);
            fail[x] = ch[getfail(fail[now])][c - 'a'];
            ch[now][c - 'a'] = x;
            if (len[x] % 4 == 0)
            {
                if (ha.get(tot - len[x] + 1, tot - len[x] / 2) == ha.get(tot - len[x] / 2 + 1, tot))
                    val[x] = x;
            }
            else
                val[x] = val[fail[x]];
        }
        last = ch[now][c - 'a'];
        cnt[last]++;
        if (val[last])
        {
            chmax(ans, len[val[last]]);
        }
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    string a;
    cin >> a;
    PAM pa(n);
    for (int i = 0; i < n; i++)
    {
        pa.insert(a[i]);
    }
    cout << pa.ans << endl;
    return 0;
}
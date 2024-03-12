#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 10;
struct PAM
{
    struct string_hash
    {
#define ll long long

        ll Q = 143, M = 1e9 + 7;
        vector<ll> h, p;
        int size = 0;
        string_hash()
        {
            size = 0;
        }
        string_hash(int n, ll q = 131, ll m = 1e9 + 7)
        {
            Q = q, M = m;
            init(n);
        }
        void init(int n)
        {
            p.resize(n + 1);
            p[0] = 1;
            for (int i = 1; i <= n; i++)
                p[i] = p[i - 1] * Q % M;
            h.push_back(0), size = 0;
        }
        void Prefix_sum_Storage(string &str) // 预处理前缀和
        {
            int n = str.size();
            h.resize(n + 1);
            str = " " + str;
            for (int i = 1; i <= n; i++)
            {
                h[i] = (h[i - 1] * Q + str[i]) % M;
            }
        }
        ll get(int l, int r) // 通过前缀和获得字串
        {
            return (h[r] - h[l - 1] * p[r - l + 1] % M + M) % M;
        }
        void insert(char c)
        {
            // cout << size << endl;
            h.push_back((h[size] * Q + c) % M);
            size++;
        }
        ll encode(string str) // 编码
        {
            ll res = 0;
            for (auto i : str)
            {
                res = (res * Q % M + i) % M;
            }
            return res;
        }
    };
    static int M;
    string_hash ha;
    int sz, tot, last;
    vector<int> cnt, len, fail; // 最长回文子串的回文后缀
    vector<array<int, 26>> ch;
    vector<char> s;
    set<ll> has;
    PAM()
    {
    }
    PAM(int n) // 开大点
    {
        init(n + 2);
        ha.init(N);
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
        ha.insert(c);
        s[++tot] = c;
        int now = getfail(last);
        if (!ch[now][c - 'a'])
        {
            int x = node(len[now] + 2);
            fail[x] = ch[getfail(fail[now])][c - 'a'];
            ch[now][c - 'a'] = x;
        }
        last = ch[now][c - 'a'];
        auto ch = ha.get(tot - len[last] + 1, tot);
        has.insert(ch);
    }
    bool query(ll k)
    {
        // cerr << tot << endl;
        if (k == tot)
            return true;
        else if (k > tot)
        {
            if (k >= 2 * tot)
                return has.find(ha.get(1, tot)) != has.end();
            else
            {
                int len = 2 * tot - k;
                int ch = k - tot;
                return ha.get(1, len) == ha.get(tot - len + 1, tot) &&
                       has.find(ha.get(tot - ch + 1, tot)) != has.end() && has.find(ha.get(1, ch)) != has.end();
            }
        }
        else
        {
            // cout << ha.get(1, 1);
            return ha.get(tot - k + 1, tot) == ha.get(1, k) && has.find(ha.get(k + 1, tot)) != has.end() &&
                   has.find(ha.get(1, tot - k)) != has.end();
        }
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string a;
    cin >> a;
    PAM pa(N);
    for (int i = 0; i < n; i++)
    {
        pa.insert(a[i]);
    }
    while (q--)
    {
        int flag;
        cin >> flag;
        if (flag == 1)
        {
            char c;
            cin >> c;
            pa.insert(c);
        }
        else
        {
            ll k;
            cin >> k;
            bool fl = pa.query(k);
            if (fl)
                cout << "Yes" << '\n';
            else
                cout << "No" << '\n';
        }
    }
    return 0;
}
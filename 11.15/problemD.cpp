#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
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
struct stable
{
    static const int K = 20;
    vector<array<int, K>> f;
    int si;
    void work(vector<int> a) // 默认从0开始
    {
        for (int i = 0; i < si; ++i)
        {
            f[i][0] = a[i];
        }
        for (int j = 1; j < K; ++j)
        {
            for (int i = 0; i + (1 << j) - 1 < si; i++)
            {
                f[i][j] = op(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int ask(int l, int r)
    {
        int len = r - l + 1;
        len = __lg(len);
        return op(f[l][len], f[r - (1 << len) + 1][len]);
    }
    virtual int op(int x, int y)
    {
        return max(x, y);
    }
};
struct St : stable
{
    St()
    {
    }
    St(vector<int> a)
    {
        si = a.size();
        f.resize(si);
        work(a);
    }
    int op(int x, int y)
    {
        return min(x, y);
    }
};
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
        l++, r++;
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
};
const int N = 5100;
i64 ans = 0;
void solve(string &a, string &b)
{
    SA sa;
    sa.s = a;
    sa.work();
    St st(sa.he);
    auto ask = [&](int l, int r) {
        if (l < 0 || r >= sa.s.size())
            return 0;
        if (l == r)
            return (int)sa.s.size() - l - 1;
        l = sa.rk[l], r = sa.rk[r];
        if (l > r)
            swap(l, r);
        return st.ask(l + 1, r);
    };
    string_hash ha(N), hb(N);
    unordered_map<i64, int> mp[N];
    ha.Prefix_sum_Storage(a), hb.Prefix_sum_Storage(b);
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = i; j < b.size(); j++)
        {
            mp[j - i + 1][hb.get(i, j)]++;
        }
    }
    i64 tem, cnt;
    for (int i = 1; i < a.size(); i++)
    {
        vector<i64> s(i + 1);
        for (int j = i - 1; j >= 0; j--)
        {
            tem = ha.get(j, i - 1);
            if (mp[i - j].find(tem) != mp[i - j].end())
                s[j] = s[j + 1] + mp[i - j][tem];
            else
                s[j] = s[j + 1];
        }
        for (int j = i - 1; j >= 0; j--)
        {
            int la = ask(j, i);
            if (la == 0)
                continue;
            int l = j + 1, r = min(i, j + la + 1);
            ans += s[l] - s[r];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    string_hash ha(N), hb(N);
    unordered_map<i64, int> mp[N];
    ha.Prefix_sum_Storage(a), hb.Prefix_sum_Storage(b);
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = i; j < b.size(); j++)
        {
            mp[j - i + 1][hb.get(i, j)]++;
        }
    }
    i64 tem;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            tem = ha.get(i, j);
            if (mp[j - i + 1].find(tem) != mp[j - i + 1].end())
                ans += mp[j - i + 1][ha.get(i, j)];
        }
    }
    solve(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    solve(b, a);
    cout << ans << endl;
    return 0;
}
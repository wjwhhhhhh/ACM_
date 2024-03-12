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
struct DSU
{
    std::vector<int> f;
    vector<array<int, 2>> siz;
    DSU()
    {
    }
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.resize(n);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        if (siz[x] < siz[y])
            swap(x, y);
        siz[x][0] += siz[y][0];
        siz[x][1] += siz[y][1];
        f[y] = x;
        return true;
    }

    auto size(int x)
    {
        return siz[find(x)];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    DSU f(2 * n);
    SA sa;
    cin >> sa.s;
    sa.s += char('z' + 1);
    string t;
    cin >> t;
    sa.s += t;
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
    for (int i = 0; i < n; i++)
        f.siz[i][0] = 1, f.siz[i + n + 1][1] = 1;
    vector<int> all;
    for (int i = 0; i < n; i++)
        all.push_back(i), all.push_back(i + n + 1);
    sort(all.begin(), all.end(), [&](int x, int y) { return sa.rk[x] < sa.rk[y]; });
    vector<int> w;
    for (int i = 1; i < all.size(); i++)
    {
        w.push_back(ask(all[i - 1], all[i]));
    }
    vector<int> o(w.size());
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return w[x] > w[y]; });

    return 0;
}
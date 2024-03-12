#include <bits/stdc++.h>
const int bug = false;
#define dug(x)                                                                                                         \
    if (bug)                                                                                                           \
    cerr << "死了吧小丑" << x << endl
#define fir(i, a, b) for (int i = a; i < b; i++)
#define far(a, b) for (auto a : b)
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
struct DSU
{
    std::vector<int> f, siz;

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
        siz.assign(n, 1);
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
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
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
    vector<int> ans(n);
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "? " << i + 1 << endl;
            int tem;
            cin >> tem;
            ans[i] = tem;
        }
    }
    else
    {
        int idx = 0;
        vector<vector<int>> mp(n);
        auto ask = [&](int u) {
            cout << "? ";
            for (int i = 0; i < k - 1; i++)
                cout << i + 1 << " ", mp[idx].push_back(i);
            cout << u + 1;
            mp[idx].push_back(u);
            cout << endl;
            int tem = 1;
            cin >> tem;
            mp[idx].push_back(tem);
            idx++;
            return tem;
        };
        DSU f(2 * n);
        vector<int> all(n);
        all[k - 1] = ask(k - 1);
        for (int i = k; i < n; i++)
        {
            all[i] = ask(i);
            // cout << all[i] << endl;
            if (all[i] == all[i - 1])
            {
                f.merge(i - 1, i);
            }
            else
                f.merge(i + n, i - 1), f.merge(i - 1 + n, i);
        }
        auto ask2 = [&](int u) {
            cout << "? ";
            for (int i = 0; i < u; i++)
                cout << i + 1 << " ", mp[idx].push_back(i);
            for (int i = u + 1; i <= k; i++)
                cout << i + 1 << " ", mp[idx].push_back(i);
            cout << endl;
            int tem = 1;
            cin >> tem;
            mp[idx].push_back(tem);
            idx++;
            return tem;
        };
        all[k - 2] = ask2(k - 2);
        if (all[k - 2] == all[k - 1])
            f.merge(k - 2, k);
        else
            f.merge(k - 2 + n, k), f.merge(k - 2, k + n);
        for (int i = k - 3; i >= 0; i--)
        {
            all[i] = ask2(i);
            if (all[i] == all[i + 1])
                f.merge(i, i + 1);
            else
                f.merge(i + n, i + 1), f.merge(i, i + n + 1);
        }
        int a = 0, b = 0;
        for (int i = 0; i < k; i++)
            if (f.same(i, 0))
                a++;
            else
                b++;
        int tem = 0;
        if (a & 1)
        {
            if (all[k - 1] & 1)
                tem = 1;
            else
                tem = 0;
        }
        else
        {
            if (all[k - 1] & 1)
                tem = 0;
            else
                tem = 1;
        }
        for (int i = 0; i < n; i++)
            if (f.same(i, 0))
                ans[i] = tem;
            else
                ans[i] = !tem;
    }
    for (int i = 0; i < n; i++)
    {
        int si = 0;
        for (int i = 0; i < k; i++)
            si += ans[i];
        if (si & 1 != ans[k])
            assert(0);
    }
    cout << "! ";
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}

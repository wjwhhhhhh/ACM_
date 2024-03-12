#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
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
        if (siz[x] < siz[y])
            swap(x, y);
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m, k;
    cin >> n >> m >> k;
    bool fl = true;
    if(n==1)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    if (m >= 2 * k + 2)
    {
        cout << "NO" << endl;
        return 0;
    }
    vector<vector<two>> tr(m + 2);
    for (int i = 1; i <= k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tr[c].push_back(two{a, b});
    }
    tr[0].push_back(two{1, n});
    tr[m + 1].push_back(two{1, n});
    for (int i = 0; i <= m + 1; i++)
    {
        tr[i].push_back({0, 0});
        tr[i].push_back({n + 1, n + 1});
    }
    auto get = [&](int id) {
        vector<two> ans;
        sort(tr[id].begin(), tr[id].end(), [&](two x, two y) { return x[0] < y[0]; });
        for (int i = 1; i < tr[id].size(); i++)
        {
            if (tr[id][i][0] - tr[id][i - 1][1] != 1)
            {
                ans.push_back({tr[id][i - 1][1] + 1, tr[id][i][0] - 1});
            }
        }
        return ans;
    };
    auto cha = [&](two &x, two &y) { return max(0, 1 + min(x[1], y[1]) - max(x[0], y[0])); };
    vector<vector<two>> all(m + 2);
    for (int i = 0; i <= m + 1; i++)
        all[i] = get(i);
    int idx = 0;
    vector<vector<int>> mp(m + 1);
    for (int i = 0; i <= m + 1; i++)
    {
        for (auto c : all[i])
            mp[i].push_back(idx++);
    }
    vector<vector<int>> edge(idx);
    auto check = [&](int in, int la) {
        int id = 0;
        vector<two> &ing = all[in];
        vector<two> &last = all[la];
        for (int i = 0; i < ing.size(); i++)
        {
            if (id >= last.size())
            {
                break;
            }
            int tem = cha(last[id], ing[i]);
            if (tem > 1)
            {
                return false;
            }
            else if (tem == 1)
            {
                edge[mp[in][i]].push_back(mp[la][id]);
            }
            while (id + 1 < last.size() && last[id + 1][0] <= ing[i][1])
            {
                id++;
                int tem = cha(last[id], ing[i]);
                if (tem > 1)
                {
                    return false;
                }
                else if (tem == 1)
                {
                    edge[mp[in][i]].push_back(mp[la][id]);
                }
            }
        }
        return true;
    };
    for (int i = 1; i <= m + 1; i++)
    {
        if (!check(i, i - 1))
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    DSU f(idx);
    for (int i = 0; i < idx; i++)
    {
        for (auto c : edge[i])
        {
            if (f.same(i, c))
            {
                cout << "NO" << endl;
                return 0;
            }
            f.merge(i, c);
        }
    }
    cout << "YES" << endl;
    return 0;
}
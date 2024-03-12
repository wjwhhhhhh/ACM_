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
    int operator[](int x)
    {
        return find(x);
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
    int n, m;
    cin >> n >> m;
    DSU f(2 * n);
    vector<vector<two>> cnt(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> c >> a >> b;
        a--, b--;
        cnt[a].push_back(two{b, c});
        cnt[b].push_back(two{a, c});
        if (f.same(a, b))
        {
            cout << "NO" << endl;
            return 0;
        }
        f.merge(a, b + n);
        f.merge(b, a + n);
    }
    vector<vector<int>> edge(n);
    set<int> has;
    vector<vector<int>> mp(2 * n);
    for (int i = 0; i < n; i++)
        mp[f.find(i)].push_back(i);
    vector<int> deg(n), dis(n);
    vector<char> flag(n);
    int ing = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> all;
        if (has.find(f.find(i)) == has.end())
        {
            for (auto c : mp[f[i]])
            {
                all.push_back(c);
                flag[c] = 'R';
                for (auto [x, y] : cnt[c])
                {
                    flag[x] = 'L';
                    all.push_back(x);
                    if (y == 2)
                    {
                        edge[c].push_back(x);
                        deg[x]++;
                    }
                    else
                        edge[x].push_back(c), deg[c]++;
                }
            }
            sort(all.begin(), all.end());
            all.erase(unique(all.begin(), all.end()), all.end());
            queue<int> q;
            int last = ing;
            for (auto c : all)
            {
                if (deg[c] == 0)
                {
                    q.push(c);
                    dis[c] = ing++;
                }
            }
            while (q.size())
            {
                int x = q.front();
                q.pop();
                for (auto c : edge[x])
                {
                    deg[c]--;
                    if (deg[c] == 0)
                    {
                        q.push(c);
                        dis[c] = ing++;
                    }
                }
            }
            if (ing - last != all.size())
            {
                cout << "NO" << endl;
                return 0;
            }
            has.insert(f.find(i));
            has.insert(f.find(i + n));
        }
    }
    cout << "YES" << endl;
    // cout << dis[0] << endl;
    for (int i = 0; i < n; i++)
    {
        cout << flag[i] << " " << dis[i] << '\n';
    }
    return 0;
}
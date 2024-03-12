#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define int __int128
#define endl '\n'
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l, r;
    cin >> n >> l >> r;

    DSU dsu(n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        dsu.merge(a, b);
    }
    for (int i = 0; i < n; i++)
    {
        if (dsu.find(i) == i)
        {
            int tem = dsu.size(i);
            ans ^= (tem >= l + r ? 0 : tem / l);
        }
    }
    if (ans)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}
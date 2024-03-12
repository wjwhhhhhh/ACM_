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
        // if (siz[x] < siz[y])
        //     swap(x, y);
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
const int N = 1e6 + 10;
vector<int> col[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    int a, b;
    cin >> a >> b;
    vector<vector<int>> mp(a, vector<int>(b));
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            cin >> mp[i][j];
    DSU f(N);
    auto in = [&](int x, int y) { return x * b + y; };
    auto out = [&](int x) { return two{x / b, x % b}; };
    map<int, int> has;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
        {
            col[mp[i][j]].push_back(in(i, j));
        }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        f.merge(x, y);
    }
    for (int i = 0; i < N; i++)
    {
        int tem = f[i];
        for (auto c : col[i])
        {
            mp[out(c)[0]][out(c)[1]] = tem;
        }
    }
    for (auto c : mp)
    {
        for (auto a : c)
            cout << a << " ";
        cout << "\n";
    }
    return 0;
}
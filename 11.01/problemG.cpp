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
const int N = 6001, M = 6000;
bool chu[N][N];
int mp[N][N];
using P = pair<int, int>;
int fac[N];
int idx[N * N];
int e[N*N], ne[N*n],h
void solve()
{
    int n, m;
    cin >> n >> m;
    set<P> has;
    int a, b, c, w, k;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        mp[a][b] = c;
        chu[a][b] = 1;
        has.insert({a, b});
    }
    int ir, sum = 0;
    int ans = 0;
    int fl;
    for (int i = 0; i < m; i++)
    {
        cin >> fl;
        if (fl == 1)
        {
            cin >> a >> b >> c;
            a = (a + ans) % M + 1, b = (b + ans) % M + 1;
            has.insert({a, b});
            mp[a][b] = c;
            chu[a][b] = 1;
        }
        else if (fl == 2)
        {
            cin >> a >> b;
            a = (a + ans) % M + 1, b = (b + ans) % M + 1;
            has.erase({a, b});
            mp[a][b] = 0;
            chu[a][b] = 0;
        }
        else if (fl == 3)
        {
            cin >> a >> b >> k >> w;
            a = (a + ans) % M + 1, b = (b + ans) % M + 1;
            for (auto [x, y] : v[k])
            {
                if (a + x < N && b + y < N && chu[a + x][b + y])
                    mp[a + x][b + x] += w;
                if (a - x > 0 && b - y > 0 && chu[a - x][b - y])
                    mp[a - x][b - y] += w;
                if (a - x > 0 && b + y < N && chu[a - x][b + y])
                    mp[a - x][b + y] += w;
                if (a + x < N && b - y > 0 && chu[a + x][b - y])
                    mp[a + x][b - y] += w;
            }
        }
        else if (fl == 4)
        {
            sum = 0;
            cin >> a >> b >> k;
            a = (a + ans) % M + 1, b = (b + ans) % M + 1;
            for (auto [x, y] : v[k])
            {
                if (a + x < N && b + y < N && chu[a + x][b + y])
                    sum += mp[a + x][b + x];
                if (a - x > 0 && b - y > 0 && chu[a - x][b - y])
                    sum += mp[a - x][b - y];
                if (a - x > 0 && b + y < N && chu[a - x][b + y])
                    sum += mp[a - x][b + y];
                if (a + x < N && b - y > 0 && chu[a + x][b - y])
                    sum += mp[a + x][b - y];
            }
            cout << '\n' << sum;
            ans = sum;
        }
    }
    for (auto [x, y] : has)
    {
        chu[x][y] = 0;
        mp[x][y] = 0;
    }
    has.clear();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    memset(idx, -1, sizeof idx);
    for (int i = 0; i < N; i++)
        fac[i] = i * i, idx[i * i] = i;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            v[fac[i] + fac[j]].push_back({i, j});
    }
    cin >> t;
    int si=0;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ":";
        solve();
    }
    return 0;
}
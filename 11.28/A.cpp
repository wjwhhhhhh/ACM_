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
const int N = 1e3 + 10;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
char mp[N][N];
bool st[N][N];
vector<two> all[N];
int ti = 0;
int n, m;
void dfs(int x, int y)
{
    all[ti].push_back({x, y});
    st[x][y] = true;
    for (int k = 0; k < 4; k++)
    {
        int a = x + dx[k], b = y + dy[k];
        if (a < 1 || b < 1 || a > n || b > m || st[a][b] || mp[a][b] == 'O')
            continue;
        dfs(a, b);
    }
}
void solve()
{
    cin >> n >> m;
    ti = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            st[i][j] = false;
            cin >> mp[i][j];
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == '.' && !st[i][j])
            {
                dfs(i, j);
                ti++;
            }
        }
    }
    vector<two> hole;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j] == 'O')
                hole.push_back({i, j});
    int ans = 0;
    for (int id = 0; id < ti; id++)
    {
        set<pair<int, int>> ing;
        vector<two> has;
        for (auto [x, y] : hole)
        {
            ing.insert({x, y});
            for (int j = 1; j < all[id].size(); j++)
            {
                ing.insert({x - all[id][j][0] + all[id][0][0], y - all[id][j][1] + all[id][0][1]});
            }
        }
        for (auto [x, y] : ing)
        {
            has.push_back({x, y});
           // cout << x << " " << y << endl;
        }
        for (int i = 0; i < all[id].size(); i++)
        {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    st[i][j] = false;
            for (auto [x, y] : has)
            {
                // cout << x << " " << y << endl;
                int a = x + all[id][i][0] - all[id][0][0];
                int b = y + all[id][i][1] - all[id][0][1];
                if (a < 1 || b < 1 || a > n || b > m)
                    continue;
                st[a][b] = true;
            }
            int l = 0, r = 0, u = 0, d = 0;
            for (int j = 0; j < all[id].size(); j++)
            {
                if (i == j)
                    continue;
                int t2 = all[id][j][0] - all[id][i][0];
                int t1 = all[id][j][1] - all[id][i][1];
                chmax(r, t1);
                chmax(l, -t1);
                chmax(u, -t2);
                chmax(d, t2);
            }
            int res = 0;
            for (int i = 1 + u; i <= n - d; i++)
            {
                for (int j = 1 + l; j <= m - r; j++)
                    if (!st[i][j] && mp[i][j] == '.')
                        res++;
            }
            ans += (res == 1);
        }
        all[id].clear();
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
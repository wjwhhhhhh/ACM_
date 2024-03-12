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
int n, m;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    cin >> n >> m;
    vector<vector<char>> mp(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];
    }
    int ig = 1;
    vector<vector<int>> id[2]{vector(n, vector<int>(m)), vector(n, vector<int>(m))};
    set<int> wei[2][26];
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (ig & 1)
        {
            for (int j = 0; j < m; j++)
            {
                wei[0][mp[i][j] - 'a'].insert(idx);
                id[0][i][j] = idx++;
            }
        }
        else
        {
            for (int j = m - 1; j >= 0; j--)
            {
                wei[0][mp[i][j] - 'a'].insert(idx);
                id[0][i][j] = idx++;
            }
        }
        ig++;
    }
    ig = 1, idx = 0;
    for (int i = 0; i < m; i++)
    {
        if (ig & 1)
        {
            for (int j = 0; j < n; j++)
            {
                wei[1][mp[j][i] - 'a'].insert(idx);
                id[1][j][i] = idx++;
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                wei[1][mp[j][i] - 'a'].insert(idx);
                id[1][j][i] = idx++;
            }
        }
        ig++;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int fl, x, y;
        cin >> fl >> x >> y;
        x--, y--;
        if (fl == 1)
        {
            char ch;
            cin >> ch;
            wei[0][mp[x][y] - 'a'].erase(id[0][x][y]);
            wei[1][mp[x][y] - 'a'].erase(id[1][x][y]);
            mp[x][y] = ch;
            wei[0][mp[x][y] - 'a'].insert(id[0][x][y]);
            wei[1][mp[x][y] - 'a'].insert(id[1][x][y]);
        }
        else if (fl == 2)
        {
            int ans = idx;
            for (int i = 0; i < 26; i++)
            {
                if (i == mp[x][y] - 'a')
                    continue;
                auto it = wei[0][i].lower_bound(id[0][x][y]);
                if (it != wei[0][i].end())
                    chmin(ans, *it);
            }
            cout << ans - id[0][x][y] << '\n';
        }
        else
        {
            int ans = idx;
            //cout << id[1][x][y] << endl;
            for (int i = 0; i < 26; i++)
            {
                if (i == mp[x][y] - 'a')
                    continue;
                auto it = wei[1][i].lower_bound(id[1][x][y]);
                if (it != wei[1][i].end())
                    chmin(ans, *it);
            }
            cout << ans - id[1][x][y] << '\n';
        }
    }
    return 0;
}
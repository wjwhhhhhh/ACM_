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
const int N = 1100;
int mp[N][N];
bool wan[N][N];
bool in[N][N];
int b[N][N];
using tr = array<int, 3>;
vector<tr> ans;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int check(int i, int j)
{
    vector<int> all;
    if (!wan[i][j])
        all.push_back(mp[i][j]);
    if (!wan[i][j + 1])
        all.push_back(mp[i][j + 1]);
    if (!wan[i + 1][j])
        all.push_back(mp[i + 1][j]);
    if (!wan[i + 1][j + 1])
        all.push_back(mp[i + 1][j + 1]);
    sort(all.begin(), all.end());
    if (all.size() == 0)
        return 0;
    else if (all[0] != all.back())
        return 0;
    else
        return all[0];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    queue<tr> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            int tem = check(i, j);
            if (tem)
            {
                q.push(tr{i, j, tem});
                in[i][j] = true;
            }
        }
    }
    while (q.size())
    {
        ans.push_back(q.front());
        auto [x, y, c] = q.front();
        q.pop();
        wan[x][y] = wan[x][y + 1] = wan[x + 1][y] = wan[x + 1][y + 1] = true;
        for (int k = 0; k < 8; k++)
        {
            int a = x + dx[k], b = y + dy[k];
            if (a >= 1 && a < n && b >= 1 && b < m)
            {
                int tem = check(a, b);
                if (tem && !in[a][b])
                {
                    q.push(tr{a, b, tem});
                    in[a][b] = true;
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto [x, y, c] : ans)
    {
        b[x][y] = b[x][y + 1] = b[x + 1][y] = b[x + 1][y + 1] = c;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (b[i][j] != mp[i][j])
            {
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto [x, y, c] : ans)
    {
        cout << x << " " << y << " " << c << '\n';
    }
    return 0;
}
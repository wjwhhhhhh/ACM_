#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 3e3 + 10;
int n, m;
char mp[N][N];
bool fl = false;
int up[N][N];
int stu[N][N];
int rig[N][N];
int sto[N][N];
int dow[N][N];
char tem[N][N];
void solve()
{
    memset(stu, 0, sizeof stu);
    memset(sto, 0, sizeof sto);
    for (int j = 1; j <= m; j++)
        up[0][j] = 1e9, dow[n + 1][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == '#')
                up[i][j] = 1e9;
            else
                up[i][j] = min(i, up[i - 1][j]);
        }
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == '#')
                dow[i][j] = 0;
            else
                dow[i][j] = max(i, dow[i + 1][j]);
        }
    }
    for (int i = 1; i <= n; i++)
        rig[m + 1][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j > 0; j--)
        {
            if (mp[i][j] == '#')
                rig[i][j] = 0;
            else
                rig[i][j] = max(j, rig[i][j + 1]);
        }
    }

    int dx, dy;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == 'S')
                dx = i, dy = j;
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (up[i][j] <= dx)
                stu[i][j] = 1;
            if (dow[i][j] >= dx)
                sto[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            stu[i][j] += stu[i][j - 1];
            sto[i][j] += sto[i][j];
        }
    }
    if (dy != m)
    {
        for (int i = dx + 1; i <= n; i++)
        {
            if (mp[i][dy] == '#')
                break;
            int l = min(rig[dx][dy], rig[i][dy]);
            if (l == dy)
                continue;
            if (stu[i][l] - stu[i][dy] > 0)
                fl = true;
        }
        for (int i = dx - 1; i > 0; i--)
        {
            if (mp[i][dy] == '#')
                break;
            int l = min(rig[dx][dy], rig[i][dy]);
            if (l == dy)
                continue;
            if (sto[i][l] - sto[i][dy] > 0)
                fl = true;
        }
    }
    for (int j = dy - 1; j > 0; j--)
    {
        if (mp[dx][j] == '#')
            break;
        for (int i = dx + 1; i <= n; i++)
        {
            if (mp[i][j] == '#')
                break;
            int l = min(rig[i][j], rig[dx][j]);
            if (l < dy)
                continue;
            if (stu[i][l] - stu[i][dy - 1] > 0)
                fl = true;
        }
        for (int i = dx - 1; i > 0; i--)
        {
            if (mp[i][j] == '#')
                break;
            int l = min(rig[i][j], rig[dx][j]);
            if (l < dy)
                continue;
            if (sto[i][l] - sto[i][dy - 1] > 0)
                fl = true;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    // solve();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            tem[j][i] = mp[i][j];
    }
    swap(n, m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            mp[i][j] = tem[i][j];
    }
    solve();
    if (fl)
    {
        cout << "Yes" << '\n';
    }
    else
        cout << "No" << '\n';
}
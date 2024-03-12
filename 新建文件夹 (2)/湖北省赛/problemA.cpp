#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
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
const int M = 998244353, N = 1e6 + 10;

int val[N];
void add(int &x, int y)
{
    x += y;
    while (x > M)
        x -= M;
    while (x < 0)
        x += M;
    return;
}
int mul(int x, int y)
{
    return 1ll * x * y % M;
}
int ctrmm[N][62];
int ctr2[N][62];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int yi[128];
    vector<char> tm(62);
    for (int i = 0; i < 26; i++)
    {
        yi[i + 'A'] = i;
        tm[i] = i + 'A';
        yi[i + 'a'] = i + 26;
        tm[i + 26] = i + 'a';
    }
    for (int i = 0; i < 10; i++)
    {
        yi[i + '0'] = i + 52;
        tm[i + 52] = i + '0';
    }
    string a;
    cin >> a;
    int n = a.size();
    vector<array<int, 62>> s(n + 1);
    fill(s[0].begin(), s[0].end(), 0);
    vector<vector<int>> mp(62);
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1];
        s[i][yi[a[i - 1]]]++;
        mp[yi[a[i - 1]]].push_back(i);
    }
    vector<int> sa(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        sa[i] = sa[i - 1];
        add(sa[i], s[i - 1][yi[a[i - 1]]]);
    }
    vector<int> cc(n + 1);
    for (int i = 2; i <= n; i++)
        cc[i] = mul(mul(i, i - 1), 499122177);
    int ans = 0;
    for (int i = 0; i < 62; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans++;
            ctrmm[j][i] = ctrmm[j - 1][i];
            if (yi[a[j - 1]] == i)
            {
                add(ctrmm[j][i], j - s[j][i]);
            }
            else
            {
                add(ctrmm[j][i], s[j][i]);
            }
        }
    }
    // for (int i = 0; i < 62; i++)
    // {
    //     if (mp[i].size() <= 1)
    //         continue;
    //     for (int j = 0; j < 62; j++)
    //     {
    //         if (i == j)
    //             continue;
    //         int f1 = 0, f2 = 0, dp1 = 0, dp2 = 0, res;
    //         f2 = s[n][j] - s[mp[i].back()][j];
    //         val[0] = 0;
    //         for (int z = 1; z < mp[i].size(); z++)
    //         {
    //             val[z] = val[z - 1];
    //             add(val[z], s[mp[i][z]][j]);
    //         }
    //         for (int z = mp[i].size() - 2; z >= 0; z--)
    //         {
    //             add(dp2, mul(s[mp[i][z + 1]][j] - s[mp[i][z]][j], f2));
    //             add(f2, (s[n][j] - s[mp[i][z]][j]) + f2);
    //             int id = mp[i][z] - 1;
    //             if (id == 1)
    //                 continue;
    //             res = ctrmm[id][i];
    //             add(res, ctrmm[id][j]);
    //             add(res, -mul(s[id][i], s[id][j]));
    //             add(res, -sa[s[id][i]]);
    //             add(res, -sa[s[id][j]]);
    //             add(ans, mul(res, dp2));
    //         }
    //     }
    // }
    cout << ans << endl;
    return 0;
}
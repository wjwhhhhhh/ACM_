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
int f(i64 x)
{
    return __builtin_popcountll(x);
}
const int N = 80, M = 128;
i64 all[N][2][N];
bool w[M][2][2];
i64 len[N][2][2];
void solve()
{
    i64 m, l;
    cin >> m >> l;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    i64 ans = 0;
    for (int i = 0; i < 128; i++)
    {
        for (int z = 0; z < 2; z++) // 前面·
        {
            for (int j = 0; j < 2; j++) // 后面
            {
                bool fl = true;
                for (int t = 0; t < m; t++)
                {
                    int tem = i + t, h;
                    if (tem >= 128)
                    {
                        h = (j - (z - 1) + 2) % 2;
                        tem -= 128;
                    }
                    else
                        h = j;
                    if ((f(tem) + h) % 2 != a[t])
                        fl = false;
                }
                w[i][z][j] = fl;
            }
        }
    }
    i64 ing = 0;
    if (l > 0)
    {
        for (int jj = __lg(l); jj >= 0; jj--)
        {
            if (!(l >> jj & 1))
                continue;
            else if (jj <= 6)
            {
                i64 xh = l;
                for (int j = 0; j <= jj; j++)
                {
                    if (l >> j & 1)
                        l -= 1 << j;
                }
                for (int i = 0; i < (1 << jj); i++)
                {
                    bool fl = true;
                    for (int j = 0; j < m; j++)
                    {
                        if (f(l + i + j) % 2 != a[j])
                            fl = false;
                    }
                    ans += fl;
                }
                l = xh;
            }
            else
            {
                for (int j = 0; j < 128; j++)
                {
                    for (int q = 0; q < 2; q++)
                    {
                        for (int h = 0; h < 2; h++)
                        {
                            if (w[j][q][(h + ing) % 2])
                            {
                                if (len[jj - 7][q][h] == 0)
                                    continue;
                                ans += len[jj - 7][q][h];
                            }
                        }
                    }
                }
                ing++;
            }
        }
    }
    bool fl = true;
    for (int j = 0; j < m; j++)
    {
        if (f(l + j) % 2 != a[j])
            fl = false;
    }
    ans += fl;
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    vector<__int128> po(N);
    po[0] = 1;
    for (int i = 1; i < N; i++)
        po[i] = po[i - 1] * 2ll;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i - 2; j++)
        {
            len[i][j & 1][0] += po[i - j - 2];
            len[i][j & 1][1] += po[i - j - 2];
        }
        if (i)
            len[i][(i - 1) & 1][(i - 1) & 1]++;
        len[i][i & 1][i & 1]++;
    }
    while (t--)
    {
        solve();
    }
    return 0;
}
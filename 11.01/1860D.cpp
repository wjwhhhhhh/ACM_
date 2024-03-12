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
const int N = 100;
int dp[2][N][N * N]; // 前i个中 01 个数
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string a;
    cin >> a;
    dp[0][0][0] = 0;
    fir(i, 0, a.size())
    {
        fir(j, 0, i + 2)
        {
            fir(z, 0, j * (i + 1 - j) + 1)
            {
                dp[1][j][z] = 1e9;
            }
        }
        fir(j, 0, i + 2)
        {
            fir(z, 0, j * (i - j) + 1)
            {
                chmin(dp[1][j + 1][z], dp[0][j][z] + (a[i] != '0'));
                chmin(dp[1][j][z + j], dp[0][j][z] + (a[i] != '1'));
            }
        }
        swap(dp[1], dp[0]);
    }
    int s0 = count(a.begin(), a.end(), '0');
    cout << dp[0][s0][s0 * (a.size() - s0) / 2] / 2 << endl;
    return 0;
}
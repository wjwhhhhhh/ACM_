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
const int N = 1e3 + 10, M = 4e6 + 10;
int f[N], w[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    i64 sum = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < i; j++)
            if (i % j == 0)
                w[i] += j;
    }
    int s;
    cin >> s;
    f[0] = 1;
    for (int i = 1; i <= s; i++)
    {
        cout << w[i] << endl;
        for (int j = s - w[i]; j >= 0; j--)
            f[j + w[i]] |= f[j];
    }
    for (int i = s; i >= 0; i--)
    {
        if (f[i])
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
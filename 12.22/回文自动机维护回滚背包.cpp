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
int ch[2];
int get(char tr)
{
    if (tr >= 'a' && tr <= 'z')
        return ch[1];
    else
        return ch[0];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    int a;
    cin >> a >> ch[0] >> ch[1];
    string aa;
    cin >> aa;
    i64 ans = 2e18;
    for (int i = 0; i < n; i++)
    {
        i64 res = i * a;
        for (int j = 0; j < n - 1 - j; j++)
        {
            int r = n - 1 - j;
            if (aa[j] == aa[r])
                continue;
            res += min({get(aa[j]), get(aa[r]), 2 * ch[1], 2 * ch[0]});
        }
        chmin(ans, res);
        aa += aa[0];
        aa = aa.substr(1);
    }
    cout << ans << endl;
    return 0;
}
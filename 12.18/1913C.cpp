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
const int N = 30;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    cout << (1 << 29) << endl;
    vector<int> cnt(30);
    while (n--)
    {
        int fl, x;
        cin >> fl >> x;
        if (fl == 1)
        {
            cnt[x]++;
        }
        else
        {
            for (int i = N - 1; i >= 0; i--)
            {
                int cn = 1 << i;
                if (x >= cn)
                {
                    int mi = min(cnt[i], x / cn);
                    x -= mi * cn;
                }
            }
            if (x == 0)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }
    return 0;
}
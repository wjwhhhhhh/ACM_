#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
const int N = 1e7;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<i64> a(N);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = n + 1; i < N; i++)
    {
        a[i] = max(0ll, 2ll * a[i - 1] - a[i - 2]);
    }
    for (int i = 1; i < N; i++)
    {
        if (a[i] < k)
        {
            cout << "Python 3." << i << " will be faster than C++" << endl;
            return 0;
        }
    }
    cout << "Python will never be faster than C++" << endl;
    return 0;
}
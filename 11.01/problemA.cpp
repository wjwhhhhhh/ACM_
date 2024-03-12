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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<int> du(n);
    fir(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        du[a]++, du[b]++;
    }
    int si = 0;
    fir(i, 0, n)
    {
        if (du[i] > 3)
        {
            cout << "0" << endl;
            return 0;
        }
        else if (du[i] == 3)
            si++;
    }
        cout << n - si << endl;
    return 0;
}
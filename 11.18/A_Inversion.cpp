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
const int N = 3e5;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    i64 n;
    cin >> n;
    string a;
    cin >> a;
    i64 si = 0, sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '<')
        {
            sum += si * (si + 1) / 2;
            si = 0;
        }
        else
            si++;
    }
    sum += si * (si + 1) / 2;
    cout << sum << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int ex_gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = ex_gcd(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - a / b * y;
    return d;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m, x, y, l;
    cin >> n >> m >> x >> y >> l;
    int x1, y1;
    int len = y - x, cha = n - m;
    if (n > m)
        cha = n - m, len = y - x;
    else
        cha = m - n, len = x - y;
    if (len % __gcd(cha, l) != 0)
    {
        cout << "Impossible";
        return 0;
    }
    ex_gcd(cha, l, x1, y1);
    x1 *= len / __gcd(cha, l), y1 *= len / __gcd(cha, l);
    int t = l / __gcd(cha, l);
    cout << (x1 % t + t) % t << endl;
    return 0;
}
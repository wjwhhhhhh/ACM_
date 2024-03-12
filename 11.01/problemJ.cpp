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
void solve()
{
    int n;
    cin >> n;
    i64 sum = 0;
    string a;
    getline(cin, a);
    while (n--)
    {
        getline(cin, a);
        auto find = [&](string th) {
            for (int i = 0; i < a.size() && i + th.size() - 1 < a.size(); i++)
            {
                if (a.substr(i, th.size()) == th)
                    return i;
            }
            return -1;
        };
        i64 si = 0;
        if (find("bool") != -1 || find("char") != -1)
            si = 1;
        else if (find("__int128") != -1 || find("long double") != -1)
            si = 16;
        else if (find("long long") != -1 || find("double") != -1)
            si = 8;
        else
            si = 4;
        if (find("[") != -1)
        {
            int c = find("[");
            c++;
            i64 tem = 0;
            while (a[c] != ']')
            {
                tem *= 10;
                tem += (a[c] - '0');
                c++;
            }
            sum += si * tem;
        }
        else
            sum += si;
    }
    int si = (sum + 1023) / 1024;
    cout << si << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
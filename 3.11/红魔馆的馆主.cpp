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
    i64 tem = 0;
    cin >> tem;
    if (tem % 495 == 0)
        cout << "-1";
    else
    {
        i64 si = tem % 495, id = 1;
        while (1)
        {
            si = si * 10 % 495;
            if (495 - si < pow(10, id))
            {
                string a = to_string(495 - si);
                while (a.size() != id)
                    a = "0" + a;
                cout << a << endl;
                break;
            }
            id++;
        }
    }
    return 0;
}
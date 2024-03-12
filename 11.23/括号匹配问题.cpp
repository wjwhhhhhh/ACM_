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
    string a;
    cin >> a;
    i64 ans = 0;
    vector<int> has;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '(')
            has.push_back(i);
        else if (has.size())
        {
            ans += 2 * (has.back() + 1) * (a.size() - i);
            has.pop_back();
        }
    }
    cout << ans << endl;
    return 0;
}
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
    vector<char> all;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        // cout << a[i] << " ";
        if (a[i] == 'A')
        {
            if (all.size() >= 2 && all[all.size() - 1] == 'B' && all[all.size() - 2] == 'C')
            {
                all.pop_back();
                all.pop_back();
            }
            else
                all.push_back(a[i]);
        }
        else
        {
            all.push_back(a[i]);
        }
    }
    reverse(all.begin(), all.end());
    for (auto c : all)
        cout << c;
    return 0;
}
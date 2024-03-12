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
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    int si = 0, ans = 0;
    vector<int> all;
    for (auto c : a)
    {
        if (c == '0')
        {
            all.push_back(si>0);
            si=0;
        }
        else si++;
        if(si==k)
        {
            all.push_back(si>0);
            si=0;
        }
    }
    cout<<accumulate(all.begin(),all.end(),0ll);
    return 0;
}
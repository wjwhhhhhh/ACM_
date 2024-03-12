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
    vector<int> a(n), b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> cnt;
    b.push_back(a[0]);
    cnt.push_back(1);
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == b.back())
        {
            cnt.back()++;
        }
        else
        {
            b.push_back(a[i]);
            cnt.push_back(1);
        }
    }
    vector<int> val(b.size(), 200);
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = i + 1; j < b.size(); j++)
        {
            if (b[j] < b[j - 1])
                break;
            else if (b[j] == b[j - 1])
                chmax(val[j], val[j - 1]);
            else
                chmax(val[j], val[j - 1] + 100);
        }
        for (int j = i - 1; j >= 0; j--)
        {
            if (b[j] < b[j + 1])
                break;
            else if (b[j] == b[j + 1])
                chmax(val[j], val[j + 1]);
            else
                chmax(val[j], val[j + 1] + 100);
        }
    }
    i64 ans = 0;
    for (int i = 0; i < b.size(); i++)
    {
        ans += cnt[i] * val[i];
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int year = 1970, kai = 3;
    map<int, int> mp;
    for (int i = 1970; i <= 2037; i++)
    {
        int si = 0;
        for (int j = 0; j < 12; j++)
        {
            int get = a[j];
            if (j == 1 && (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)))
                get = 29;
            si++;
            get -= (7 - kai);
            si += get / 7;
            if (get % 7 != 0)
                si++;
            kai = get % 7;
            // cout << kai << endl;
        }
        mp[i] = si;
        // cout << si << endl;
    }
    int n;
    cin >> n;
    cout << mp[n] << endl;
    return 0;
}
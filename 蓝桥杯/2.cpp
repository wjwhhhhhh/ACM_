#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    i64 n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];
    i64 l = 0, r = 1e12;
    auto check = [&](int x)
    {
        int si=0;
        for(int i=0;i<n;i++)
        {
            int tem=max(x-a[i],0);
            if(tem>b[i])return false;
            si+=tem;
        }
        return m>=si;
    }
    while (l < r)
    {
        i64 min = l + r + 1 >> 1;
        if (check(mid))l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
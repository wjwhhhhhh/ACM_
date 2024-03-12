#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl;
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set<int> has;
    for (int i = 0; i < n; i++)
        if (a[i] == 0)
            has.insert(i);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i])
        {
            int l = i;
            bool fl = false;
            while (i < n && a[i])
            {
                if (a[i] == 2)
                    fl = true;
                i++;
            }
            int r = i - 1;
            ans++;
            if (fl)
            {
                has.erase(l - 1), has.erase(r + 1);
            }
            else
            {
                if (has.find(l - 1) != has.end())
                    has.erase(l - 1);
                else
                    has.erase(r + 1);
            }
        }
    }
    cout << ans + has.size() << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> f(3);
        for (int i = 0; i < 3; i++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                if ((n - x) % 2 == 0)
                    f[i] = 4;
                else
                    f[i] = 0;
            }
            else if (x == n)
            {
                if ((x - 1) % 2 == 0)
                    f[i] = 4;
                else
                    f[i] = 0;
            }
            else if ((x - 1) % 2 == 1 && (n - x) % 2 == 1)
                f[i] = 0;
            else if ((x - 1) % 2 == 0 && (n - x) % 2 == 0)
                f[i] = 4;
            else
                f[i] = 1;
        }
        bool fl;
        int sum = f[0] + f[1] + f[2];
        if (sum == 0 || sum == 1 || sum == 2 || sum == 3 || sum == 5 || sum == 8 || sum == 9)
            fl = true;
        else
            fl = false;
        if (fl)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    bool fl = false;
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
            for (int z = 1; z <= 6; z++)
            {
                int a = 0, b = 0;
                if (i == 1 || i == 4)
                    a += i;
                else
                    b += i;
                if (j == 1 || j == 4)
                    a += j;
                else
                    b += j;
                if (z == 1 || z == 4)
                    a += z;
                else
                    b += z;
                if (a == n && b == m)
                    fl = true;
            }
    if (fl)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
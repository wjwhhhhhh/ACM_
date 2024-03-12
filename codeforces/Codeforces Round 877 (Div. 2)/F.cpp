#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int l = 1, r = n;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++)for (int j = 0; j <= n; j++)a[i] += '<';
    while (l < r)
    {

        int mid = l + r >> 1;
        cout << "? " << l << " " << mid << endl;
        for (int i = l; l <= mid; l++)
        {
            if ((i - l) % 2 == 0)
            {
                for (int j = 1; j < n; j++)a[i][j] = 'v';
                a[i][n] = '>';
            }
            else
            {
                for (int j = 2; j <= n; j++)a[i][j] = '^';
                a[i][1] = '>';
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
        int x, y;
        cin >> x >> y;
        if (x == -1 && y == -1)
        {
            l = mid + 1;
            continue;
        }
        if()

    }
    return 0;
}
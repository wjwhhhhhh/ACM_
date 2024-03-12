#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6 + 10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> has(N);
    for (i64 i = 2; i < N; i++)
    {
        i64 sum = 1 + i + i * i, l = i * i;

        if (sum < N)
            has[sum] = true;
        for (int j = 1; sum < N; j++)
        {
            l *= i;
            sum += l;
            if (sum == 255)
                cout << i << endl;
            if (sum < N)
                has[sum] = true;
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        if (has[a])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
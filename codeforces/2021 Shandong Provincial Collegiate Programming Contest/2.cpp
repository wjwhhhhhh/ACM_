#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int tem;
        cin >> tem;
        sum += tem;
    }
    int ans = sum / n;
    int tem = sum % n;
    cout << ans << ".";
    for (int i = 1; i <= k; i++)
    {
        tem *= 10;
        if (tem < n)cout << '0';
        else {
            int t = tem / n;
            tem = tem % n;
            cout << t;
        }
    }
    return 0;
}
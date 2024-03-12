#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
void solves()
{
    int n, k;
    cin >> n >> k;
    bitset<N>t, b;
    string tem;
    cin >> tem;
    for (int i = 0; i < tem.size(); i++)
    {
        t[i] = (tem[i] == '1');
    }
    b = t;
    long long sum = 0;
    for (int i = 0; i <= k; i++)
    {
        sum += t.count();
        //cout<<sum<<endl;
        if (k != n)
        {
            b >>= 1;
            t |= b;
            t[n - i - 1] = 0;
        }
    }
    cout << sum << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solves();
    }
    return 0;
}
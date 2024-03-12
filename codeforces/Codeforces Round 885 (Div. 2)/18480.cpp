#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
long long qmi(long long k, long long p = M - 2, long long P = M)
{
    long long res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % P;
        k = k * k % P;
        p >>= 1;
    }
    return res;
}
map<array<int, 3>, int> mp;
long long p;
int dfs(int a, int b, int wei)
{
    if (a >= b)
        return 1;
    if (a < wei)
        return 0;
    if (mp.find({a, b, wei}) != mp.end())
        return mp[{a, b, wei}];
    return (p * dfs(a + wei, b, 1) % M + p * dfs(a - wei, b, 2 * wei) % M) % M;
}
int main()
{
    int a, b;
    p = 1 * qmi(2);
    cin >> a >> b;
    cout << dfs(a, a + b, 1);
}
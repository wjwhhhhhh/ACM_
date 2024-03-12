#include <bits/stdc++.h>
using namespace std;
using i64=long long;
const int M=998244353;
long long qmi(long long k, long long p = M - 2)
{
    long long res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % M;
        k = k * k % M;
        p >>= 1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    i64 ans=qmi(2,n-1);
    cout<<ans<<endl;
    return 0;
}
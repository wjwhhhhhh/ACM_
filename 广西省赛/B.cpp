#include <bits/stdc++.h>
using namespace std;
using i64=long long;
const int M = 1e9+7;
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
    if(n==2)
    {
        cout<<26<<" "<<650<<" "<<0<<endl;
        return 0;
    }
    cout<<26<<" "<<0<<" ";
    int ans=qmi(26,n);
    cout<<(ans-26+M)%M;
    return 0;
}
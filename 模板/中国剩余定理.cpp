#include <bits/stdc++.h>
using namespace std;
using i64=long long;
//即求满足以下条件的整数：除以 3 余 2，除以 5 余 3，除以 7 余 2。
//要求模数互质
int exgcd(i64 a, i64 b, i64 &x, i64 &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
i64 CRT(vector<int>&a,vector<int>&mod)
{
    i64 n=1,ans=0;
    for(auto x:mod)n*=x;
    for(int i=0;i<a.size();i++)
    {
        i64 m=n/mod[i],b,y;
        exgcd(m,mod[i],b,y);
         ans = (ans + a[i] * m * b % n) % n;
    }
    return (ans % n + n) % n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    }
    return 0;
}
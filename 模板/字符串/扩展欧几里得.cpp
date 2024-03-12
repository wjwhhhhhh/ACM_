#include <bits/stdc++.h>
using namespace std;
using i64=long long;
int exgcd(int a, int b, int &x, int &y)
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
ax+by=gcd(a,b);
最正数
int t=b/(gcd(a,b));
x=(x%t+t)%t;

通解
x= x1+k*gcd(a,b);
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
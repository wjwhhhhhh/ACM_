#include <bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=1e6+10,M=1e9+7;
int tr[N];
int lowbit(int x)
{
    return x&-x;
}
void update(int x,int c)
{
    for(int i=x;i<N;i+=lowbit(i))tr[i]=(tr[i]+c)%M;
}
int ask(int x)
{
    int res=0;
    if(x<=0)return 0;
    for(int i=x;i;i-=lowbit(i))res=(res+tr[i])%M;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    std::vector<int> v(n),f(n);
    int ans=0;
    for(int i=0;i<n;i++)cin>>v[i];
    for(auto i:v)
    {
        f[i]=((1+ask(i-k))%M+(ask(N-1)-ask(i+k-1))%M)%M;
        update(i,f[i]);
        ans=(ans+f[i])%M;
    }
    cout<<(ans+M)%M<<endl;
    return 0;
}
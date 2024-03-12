#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    int n = str.size();
    str = " " + str;
    std::vector<int> f(n+1);
    int q=0,p=0;
    for(int i=1;i<=n;i++)
    {
        f[i]=1;
//         for(int j=i-1;j;j--)
//         {
//             if(str[i]=='1'&&str[j]=='6')continue;
//             f[i]=(f[i]+f[j])%M;;
//         }
        if(str[i]=='6')
        {
            f[i]=(f[i]+q)%M;
            p=(p+f[i])%M;
        }
        else if(str[i]=='1')
        {
            f[i]=(f[i]+q-p+M)%M;
        }
        else
        {
            f[i]=(f[i]+q)%M;
        }
         q=(q+f[i])%M;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+f[i])%M;
    }
    cout<<ans<<endl;
    return 0;
}
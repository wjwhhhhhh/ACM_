#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin>>a;
    int n=a.size();
    vector<int>cn(2,0);
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='0')cn[0]++;
    }
    cn[1]=n-cn[0];
    vector<int> ans(2,0);
    for(int i=0;i<2;i++)
    {
        stack<int> has;
        for(int j=0;j<n;j++)
        {
            if(j&1)
            {
                if(a.substr(j,1)==to_string(i))has.push(j);
            }
            else 
            {
                if(a.substr(j,1)!=to_string(i))
                {
                    if(has.size())ans[i]+=abs(has.top()-j);
                }
            }
        }
    }
    if(cn[1]>cn[0])cout<<ans[1];
    else if(cn[1]==cn[0])cout<<
    return 0;
}
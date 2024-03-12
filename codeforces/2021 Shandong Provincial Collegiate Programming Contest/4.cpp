#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long k;
    cin>>k;
    if(k<10)
    {
        cout<<k-1<<'\n';
        for(int i=1;i<=k-2;i++)cout<<i<<" "<<i+1<<'\n';
    }
    else
    {
        int root=1,si=2;
        k--;
        while(k)
        {
            cerr<<k<<endl;
            if(k==3)
            {
                ans.push_back({si+2,root});
                ans.push_back({si+1,si+2});
                break;
            }
            if(k==2)
            {
                ans.push_back({si,root});
                break;
            }
            if(k%2==0)
            {
                ans.push_back({si,root});
                si++;
                k>>=1;
            }
            else
            {
                ans.push_back({si,root});
                root=si;si++;
                k--;
            }
        }
        cout<<ans.size()<<'\n';
        for(auto i:ans)cout<<i.first<<' '<<i.second<<'\n';
    }
    return 0;
}
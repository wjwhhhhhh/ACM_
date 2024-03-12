#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64=long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        if(*min_element(a.begin(),a.end())>=0)
        {
            cout<<n-1<<endl;
            for(int i=1;i<n;i++)
            {
                cout<<i+1<<" "<<i<<'\n';
            }
            continue;
        }
        if(*max_element(a.begin(),a.end())<=0)
        {
            cout<<n-1<<endl;
            for(int i=n-2;i>=0;i--)
            {
                cout<<i+1<<" "<<i+2<<'\n';
            }
            continue;
        }
        int ma=*max_element(a.begin(),a.end());
        int id=find(a.begin(),a.end(),ma)-a.begin();
        vector<array<int,2> > ans;
        while(ma<20)
        {
            ma<<=1;
            ans.push_back({id+1,id+1});
        }
        ans.push_back({1,id+1});
        ans.push_back({1,id+1});
        for(int i=1;i<n;i++)
        {
            ans.push_back({i+1,i});
            ans.push_back({i+1,i});
        }
        cout<<ans.size()<<'\n';
        for(auto [x,y]:ans)cout<<x<<" "<<y<<'\n';
    }
    return 0;
}
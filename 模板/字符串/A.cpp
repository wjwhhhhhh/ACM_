#include <bits/stdc++.h>
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
        if(n<=4)
        {
            cout<<"Bob"<<endl;
        }
        else cout<<"Alice"<<endl;
    }
    return 0;
}
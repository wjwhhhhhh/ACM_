#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
int check(vector<int>&a,int x)
{
    for(auto i:a)
    {
        if(i%x!=0&&(i-1)/2<x)return false;
    }
    return true;
}
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=a[0];i;i--)
    {
        if(check(a,i))
        {
            cout<<i<<endl;
            return ;
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t = 1;
//    std::cin >> t;

    while (t --) {
        solve();
    }

    return 0;
}
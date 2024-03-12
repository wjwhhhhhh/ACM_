/*
    时间复杂度为（n+w) w代表值域
*/
#include <bits/stdc++.h>
using namespace std;
void counting_sort(int a[],int l,int r,int w)
{
    vector<int> cnt(w),b(l-r+10);
    for(int i=l;i<=r;i++)cnt[a[i]]++;
    for(int i=1;i<=w;i++)cnt[i]+=cnt[i-1];
    for(int i=r;i>=l;i--)b[cnt[a[i]]--]=a[i];
    for(int i=l;i<=r;i++)a[i]=b[i];
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
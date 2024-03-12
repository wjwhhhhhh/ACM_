#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
//线段树 略。。。。。使用unsigbed 0之后变正无穷
//从0开始的线段树
void solve()
{
    int n;
    vector<int> a(n);
    i64 ans=1ll*n*(n+1)/2;
    for(int i=0;i<n;i++)
    {
        seg;//初始为正无穷
        for(int j=i;j<n;j++)
        {
            int rk=(j-排序后的位置);
            seg.mody(a[j],n-1);//减一
            seg.xiugai(a[j],rk);//把第a【j]改为rk
            if(seg.query())ans--;//有1在
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64=long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int>up[101],front[101],right[101],down[101],back[101],left[101];
    int n;
    cin>>n;
    vector<array<int,6>> has(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<6;j++)cin>>has[i][j];
            up[has[i][5]].push_back(i);
            front[has[i][3]].push_back(i);
            back[has[i][0]],push_back(i);
            right[has[i][4]].push_back(i);

    }
    vector<int> ans(n);
    return 0;
}
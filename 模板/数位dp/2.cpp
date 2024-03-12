#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1000000007,W=10;
map<int, int>dp[10];
long long A[W][W] = {
{0,1,1,1,1  ,1,1,1,1,1},
};
long long B[W][W] = {
{1,1,1,0,0,   0,0,0,0,0},
{1,1,1,1,0,   0,0,0,0,0},
{1,1,1,1,1,   0,0,0,0,0},
{0,1,1,1,1,   1,0,0,0,0},
{0,0,1,1,1,   1,1,0,0,0},

{0,0,0,1,1,   1,1,1,0,0},
{0,0,0,0,1,   1,1,1,1,0},
{0,0,0,0,0,   1,1,1,1,1},
{0,0,0,0,0,   0,1,1,1,1},
{0,0,0,0,0,   0,0,1,1,1}
};
void mul(long long ans[W][W], long long A[W][W], long long B[W][W])
{
    long long tem[W][W]={0};
    for (int i = 0; i < W; i++)
        for (int j = 0; j < W; j++)
            for (int k = 0; k < W; k++)
            {
                tem[i][j] = (tem[i][j] + A[i][k] * B[k][j]) % M;
            }
    memcpy(ans, tem, sizeof tem);
}
long long qmi(long long q)
{
    //cout<<q<<endl;
    long long res = 0;
    while (q)
    {
        if (q & 1)
            mul(A, A, B);
        mul(B, B, B);
        q >>= 1ll;
    }
    for(int i=0;i<=9;i++)res=(res+A[0][i])%M;
        return res;
}
int dfs(int cur)
{
    int res = 0;
    res=qmi(cur-1);
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    if(k==1)cout<<10;
    else cout << dfs(k) << endl;
    return 0;
}
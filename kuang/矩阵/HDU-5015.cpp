#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
template<class T> void chkmax(T &a, T b) {a > b ? (a = a) : (a = b);}
template<class T> void chkmin(T &a, T b) {a > b ? (a = b) : (a = a);}
struct Matrix//横的乘竖的，记得清零
{
    static const int M=1e9+7, W=12;
    array<array<int,W> ,W> val;
    Matrix()
    {
        for(int i=0;i<W;i++)for(int j=0;j<W;j++)val[i][j]=0;
    }
    friend Matrix operator*(const Matrix A, const Matrix B)
    {
        Matrix C;
        for (int i = 0; i < W; i++)
            for (int j = 0; j < W; j++)
                for (int k = 0; k < W; k++)
                {
                    C.val[i][j] =(C.val[i][j]+ 1ll*A.val[i][k] * B.val[k][j]%M)%M;
                }
        return C;
    }
};
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m)
    {
        Matrix b;
        int n;
        cin>>n;
        for(int i=2;i<n+2;i++)cin>>b.val[0][i];
        b.val[0][0]=3,b.val[0][1]=233;
        Matrix a;
        a.val[0][0]=1;
        a.val[0][1]=1,a.val[1][1]=10;
        for(int i=2;i<n+2;i++)
        {
            a.val[1][i]=1;
            for(int j=2;j<=i;j++)a.val[j][i]=1;
        }
        m--;
        while(m)
        {
            if(m&1)b=b*a;
            a=a*a;
            m>>=1;
        }
        cout<<b.val[0][n+1]<<endl;
    }
    return 0;
}
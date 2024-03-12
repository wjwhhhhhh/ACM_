#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
template<class T> void chkmax(T &a, T b) {a > b ? (a = a) : (a = b);}
template<class T> void chkmin(T &a, T b) {a > b ? (a = b) : (a = a);}
const int M=1e9+7;
struct Matrix//横的乘竖的，记得清零
{
    static const int M=1e9+7, W=2;
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x,y;
    cin>>x>>y;
    Matrix a;
    a.val[1][0]=1,a.val[0][1]=-1,a.val[1][1]=1;
    Matrix b;
    b.val[0][0]=x,b.val[0][1]=y;
    int n;
    cin>>n;
    n--;
    while(n)
    {
        if(n&1)b=b*a;
        a=a*a;
        n>>=1;
    }
    //cout<<b.val[0][0]<<endl;
    cout<<(b.val[0][0]%M+M)%M<<endl;
    return 0;
}
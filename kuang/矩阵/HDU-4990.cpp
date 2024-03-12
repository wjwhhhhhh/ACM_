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
    static const int  W=4;
    static int M;
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
int Matrix::M=1e9;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    while(cin>>n>>m)
    {
        Matrix::M=m;
        Matrix a;
        a.val[0][0]=1;
        Matrix b;
        b.val[0][0]=0,b.val[0][1]=1,b.val[0][2]=1,b.val[0][3]=1;
        b.val[1][0]=1,b.val[1][1]=0,b.val[1][2]=0,b.val[1][3]=0;
        b.val[2][0]=0,b.val[2][1]=0,b.val[2][2]=1,b.val[2][3]=1;
        b.val[3][0]=0,b.val[3][1]=0,b.val[3][2]=1,b.val[3][3]=1;
        while(n)
        {
            if(n&1)a=a*b;
            b=b*b;
            n>>=1;
        }
        cout<<a.val[0][2]<<endl;
    }
    return 0;
}
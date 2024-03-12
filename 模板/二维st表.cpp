#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<n;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
struct Twost
{
    static const int W=10;
    vector<vector<array<array<int,W>,W>>>f;
    int _n,_m;
    void work()
    {
        for(int k1=0;k1<W;k1++)for(int k2=0;k2<W;k2++)
        for(int i=0;i+(1<<k1)-1<_n;i++)for(int j=0;j+(1<<k2)-1<_m;j++)
        {
                if(k1==0&&k2==0)continue;
                if(k1)
                {
                    f[i][j][k1][k2]=
                    op(f[i][j][k1-1][k2],f[i+(1<<k1-1)][j][k1-1][k2]);
                }
                else
                {
                    f[i][j][k1][k2]=
                    op(f[i][j][k1][k2-1],f[i][j+(1<<k2-1)][k1][k2-1]);
                }
        }
    }
    int ask(int x1,int y1,int x2,int y2)
    {
        int len1=__lg(x2-x1+1),len2=__lg(y2-y1+1);
        return op(f[x1][y1][len1][len2],
            op(f[x2-(1<<len1)+1][y1][len1][len2],
                op(f[x1][y2-(1<<len2)+1][len1][len2],
                f[x2-(1<<len1)+1][y2-(1<<len2)+1][len1][len2])));
    }
    virtual int op(const int& x, const int& y)
    {
        return min(x, y);
    }

};
struct TwoSt : Twost
{
    TwoSt()
    {
    }
    TwoSt(int n,int m)
    {

        _n=n,_m=m;
        f.resize(_n);
        for(int i=0;i<_n;i++)f[i].resize(_m);

    }
    void init(vector<vector<int> >&a)
    {
        for(int i=0;i<_n;i++)for(int j=0;j<_m;j++)f[i][j][0][0]=a[i][j];
        work();
    }
    int op(const int& x, const int& y)
    {
        return max(x, y);
    }
};
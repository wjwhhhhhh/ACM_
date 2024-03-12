#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define int __int128
#define endl '\n'
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
using i64 = long long;
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
inline int read()
{
    char c = getchar();
    int x = 0, s = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            s = -1;
        c = getchar();
    } // 是符号
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    } // 是数字
    return x * s;
}
void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

struct Matrix//横的乘竖的，记得清零
{
    static const int M=1e9+7, W=11;
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}
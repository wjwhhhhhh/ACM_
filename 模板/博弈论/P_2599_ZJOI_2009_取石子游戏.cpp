#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define int __int128
#define endl '\n'
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
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
const int N=1010;
int a[N],L[N][N],R[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        fir(i,1,n)cin>>a[i];
        fir(i,1,n)L[i][i]=R[i][i]=a[i];
        fir(len,2,n)fir(i,i+len-1,n)
        {
            int j=i+len-1;
            int x=a[j],l=L[i][j-1],r=R[i][j-1];
            if(x==r)L[i][j]=0;
            else if()
        }
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}
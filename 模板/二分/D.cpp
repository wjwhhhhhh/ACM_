#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define int __int128
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
const int N=2e5+10;
int n, k, m, c, d;
int qian[N];
int dist[N];
bool ch(int y,int i,int x)
{
    return dist[i]+c+d*(y-1)>=x;
}
bool check(int x)
{
    met(qian,0);
    for(int i=1;i<=n;i++)
    {
        if(dist[i]+c+d*(m-1)<x)continue;
        else if(dist[i]>=x)qian[0]++;
        else 
        {
            int l=1,r=m;
            while(l<r)
            {
                int mid=l+r>>1;
                if(ch(mid,i,x))r=mid;
                else l=mid+1;
            }
            l=max(1ll,i-m+1),r=i-r+1;
            if(l>r)continue;;
            qian[l]++,qian[r+1]--;
        }
    }
    for(int i=1;i<=n+1;i++)
    {
        qian[i]+=qian[i-1];
        if(qian[i]>=k)return true;
    }
    return false;
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cin>>n>>k>>m>>c>>d;
    for(int i=1;i<=n;i++)cin>>dist[i];
    int l=1,r=0x3f3f3f3f3f3f3f3f;
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}
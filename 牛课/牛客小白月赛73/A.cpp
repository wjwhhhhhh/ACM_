#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define cyes cout<<"YES\n"
#define cno cout<<"NO\n"
#define calice cout<<"Alice\n"
#define cbob cout<<"Bob\n"
#define mem(a) memset((a),0,sizeof (a))
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << endl
#define ii pair<ll,ll>
#define lb lower_bound
#define ub upper_bound
#define nxtper next_permutation
#define cmpmax greater<int>()
#define upchu(a,b) (((a)+(b)-1)/b)
#define all(x) x.begin(), x.end()
#define eback emplace_back
#define is_out(x) ((double)clock()/CLOCKS_PER_SEC<=x)
#define rep(a,b) for(int (a) = 1;(a)<=(b);(a)++)
//#pragma GCC optimize(2)

const int mod7 = 1e9+7;
const int mod9 = 998244353;
const int INF = 1e9;
const ll LNF = 1e18;
const double eps = 1e-4;
int fx[4] = {-1,0,1,0};
int fy[4] = {0,-1,0,1};


const int nn = 2e5+10;
ll a[nn];
ll c2[nn],c5[nn];
ll s2[nn],s5[nn];
int c(int l1, int r1, int l2, int r2) {
  int res = min(r1, r2) - max(l1, l2) + 1;
  return max(res, 0);
}
void solve()
{
    ll n;ll k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c2[i] = c5[i] = 0;
        while(a[i]%2==0) a[i]/=2,c2[i]++;
        while(a[i]%5==0) a[i]/=5,c5[i]++;
    }
    for(int i=1;i<=n;i++)
        s2[i] = s2[i-1] + c2[i];
    for(int i=1;i<=n;i++)
        s5[i] = s5[i-1] + c5[i];

    ll ans = 0;
    for(int i=1;i<=n;i++){
        int l1 = lb(s2+1,s2+n+1,s2[i-1]+k) - s2;
        int r1 = ub(s2+1,s2+n+1,s2[i-1]+k) - s2-1;

        int l2 = lb(s5+1,s5+n+1,s5[i-1]+k) - s5;
        int r2 = ub(s5+1,s5+n+1,s5[i-1]+k) - s5-1;
        l1 = max(i,l1);r1 = max(i,r1);l2 = max(i,l2);r2 = max(i,r2);
        if (s2[l1] == s2[i - 1] + k) ans += c(l1, r1, l2, n);
        if (s5[l2] == s5[i - 1] + k) ans += c(l1, n, l2, r2);
        if (s2[l1] == s2[i - 1] + k && s5[l2] == s5[i - 1] + k) ans -= c(l1, r1, l2, r2);

//
        // l1 = max(i,l1);r1 = max(i,r1);l2 = max(i,l2);r2 = max(i,r2);
//
        // if(s2[l1]==s2[i-1]+k)
            // ans+=c(l1,r1,l2,n);//max(0,min(pos3,n)-max(pos1,pos2)+1);
        // if(s5[l2]==s5[i-1]+k);
            // ans+=c(l1,n,l2,r2);//max(0,min(pos4,n)-max(pos1,pos2)+1);
//
        // if(s2[l1]==s2[i-1]+k && s5[l2]==s5[i-1]+k)
            // ans-=c(l1,r1,l2,r2);//max(0,(min(pos3,pos4) - max(pos1,pos2)+1));
        // // if (s2[l1] == s2[i - 1] + k) ans += c(l1, r1, l2, n);
        // // if (s5[l2] == s5[i - 1] + k) ans += c(l1, n, l2, r2);
        // // if (s2[l1] == s2[i - 1] + k && s5[l2] == s5[i - 1] + k) ans -= c(l1, r1, l2, r2);
    }
    cout<<ans<<endl;
}
int main()
{
    //cin.ignore(numeric_limits<streamsize>::max(),'\n');
    ios_base::sync_with_stdio(0); cin.tie(0); //cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
}



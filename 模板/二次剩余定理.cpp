#include <bits/stdc++.h>
using namespace std;
using i64=long long;
const int M = 998244353;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T qmi(T k, long long p = M - 2,long long P=M)
{
    T res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % P;
        k = k * k % P;
        p >>= 1;
    }
    return res;
}
struct Complex
{
    i64 x, y;
    static int I_mul_I;
    static int MOD;
    Complex(i64 _x = 0, i64 _y = 0)
    {
        x = _x;
        y = _y;
    }

    Complex operator-(const Complex &b) const
    {
        return Complex(x - b.x, y - b.y);
    }

    Complex operator+(const Complex &b) const
    {
        return Complex(x + b.x, y + b.y);
    }

    Complex operator*(const Complex &b) const
    {
        return Complex((x * b.x%MOD + (y * b.y%MOD)*I_mul_I%MOD)%MOD, (x * b.y%MOD + y * b.x%MOD)%MOD);
    }
    Complex operator%(const int &P)const
    {
        return Complex(x%P,y%P);
    }
};
int Complex:: I_mul_I=1;
int Complex::MOD=1;
bool is_quadratic_residue(i64 n,i64 p)//判断是不是二次剩余,要奇素数,(p-1>>1)对
{
    if(n==0)return true;
    if(qmi((i64)n,(p-1)>>1,p)==1)return true;
    else return false;
}
pair<int,int>Cipolla(i64 n,i64 p)
{
    if(n==0)return make_pair(0,0);
    i64 a;
    while(1)
    {
        a=rng()%p;
        Complex ::I_mul_I=((a*a%p-n)%p+p)%p;//a^2 -n
        if(!is_quadratic_residue(Complex ::I_mul_I,p))break;
    }
    Complex ing(a,1);
    Complex ::MOD=p;
    ing = qmi(ing,p+1>>1,p);
    i64 ans1=ing.x%p,ans2=(p-ans1)%p;
    return make_pair(ans1,ans2);
}
int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        if(!is_quadratic_residue(n,p))
        {
            cout<<"Hola!"<<endl;
            continue;
        }
        auto get=Cipolla(n,p);
        if(get.first>get.second)swap(get.first,get.second);
        cout<<get.first<<" ";
        if(get.first!=get.second)cout<<get.second;
        cout<<endl;
    }
}
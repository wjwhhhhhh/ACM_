#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
struct Complex
{
    double x, y;
    Complex(double _x = 0.0, double _y = 0.0)
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
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};
void change(Complex y[], int len)
{
    int i, j, k;
    for (int i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j)
            swap(y[i], y[j]);
        k = len / 2;
        while (j >= k)
        {
            j = j - k;
            k = k / 2;
        }
        if (j < k)
            j += k;
    }
}
void fft(Complex y[], int len, int on)
{
    change(y, len);
    for (int h = 2; h <= len; h <<= 1)
    {
        Complex wn(cos(on * 2 * PI / h), sin(on * 2 * PI / h));
        for (int j = 0; j < len; j += h)
        {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++)
            {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1)
    {
        for (int i = 0; i < len; i++)
        {
            y[i].x /= len;
        }
    }
}
class BigInt
{
#define Value(x, nega) ((nega) ? -(x) : (x))
#define At(vec, index) ((index) < vec.size() ? vec[(index)] : 0)
    static int absComp(const BigInt &lhs, const BigInt &rhs)
    {
        if (lhs.size() != rhs.size())
            return lhs.size() < rhs.size() ? -1 : 1;
        for (int i = lhs.size() - 1; i >= 0; --i)
            if (lhs[i] != rhs[i])
                return lhs[i] < rhs[i] ? -1 : 1;
        return 0;
    }
    using Long = long long;
    const static int Exp = 9;
    const static Long Mod = 1000000000;
    mutable std::vector<Long> val;
    mutable bool nega = false;
    void trim() const
    {
        while (val.size() && val.back() == 0)
            val.pop_back();
        if (val.empty())
            nega = false;
    }
    int size() const
    {
        return val.size();
    }
    Long &operator[](int index) const
    {
        return val[index];
    }
    Long &back() const
    {
        return val.back();
    }
    BigInt(int size, bool nega) : val(size), nega(nega)
    {
    }
    BigInt(const std::vector<Long> &val, bool nega) : val(val), nega(nega)
    {
    }

  public:
    friend std::ostream &operator<<(std::ostream &os, const BigInt &n)
    {
        if (n.size())
        {
            if (n.nega)
                putchar('-');
            for (int i = n.size() - 1; i >= 0; --i)
            {
                if (i == n.size() - 1)
                    printf("%lld", n[i]);
                else
                    printf("%0*lld", n.Exp, n[i]);
            }
        }
        else
            putchar('0');
        return os;
    }
    friend BigInt operator+(const BigInt &lhs, const BigInt &rhs)
    {
        BigInt ret(lhs);
        return ret += rhs;
    }
    friend BigInt operator-(const BigInt &lhs, const BigInt &rhs)
    {
        BigInt ret(lhs);
        return ret -= rhs;
    }
    BigInt(Long x = 0)
    {
        if (x < 0)
            x = -x, nega = true;
        while (x >= Mod)
            val.push_back(x % Mod), x /= Mod;
        if (x)
            val.push_back(x);
    }
    BigInt(const char *s)
    {
        int bound = 0, pos;
        if (s[0] == '-')
            nega = true, bound = 1;
        Long cur = 0, pow = 1;
        for (pos = strlen(s) - 1; pos >= Exp + bound - 1; pos -= Exp, val.push_back(cur), cur = 0, pow = 1)
            for (int i = pos; i > pos - Exp; --i)
                cur += (s[i] - '0') * pow, pow *= 10;
        for (cur = 0, pow = 1; pos >= bound; --pos)
            cur += (s[pos] - '0') * pow, pow *= 10;
        if (cur)
            val.push_back(cur);
    }
    BigInt &operator=(const char *s)
    {
        BigInt n(s);
        *this = n;
        return n;
    }
    BigInt &operator=(const Long x)
    {
        BigInt n(x);
        *this = n;
        return n;
    }
    friend std::istream &operator>>(std::istream &is, BigInt &n)
    {
        string s;
        is >> s;
        n = (char *)s.data();
        return is;
    }
    BigInt &operator+=(const BigInt &rhs)
    {
        const int cap = std::max(size(), rhs.size()) + 1;
        val.resize(cap);
        int carry = 0;
        for (int i = 0; i < cap - 1; ++i)
        {
            val[i] = Value(val[i], nega) + Value(At(rhs, i), rhs.nega) + carry, carry = 0;
            if (val[i] >= Mod)
                val[i] -= Mod, carry = 1;
            else if (val[i] < 0)
                val[i] += Mod, carry = -1;
        }
        if ((val.back() = carry) == -1) // assert(val.back() == 1 or 0 or -1)
        {
            nega = true, val.pop_back();
            bool tailZero = true;
            for (int i = 0; i < cap - 1; ++i)
            {
                if (tailZero && val[i])
                    val[i] = Mod - val[i], tailZero = false;
                else
                    val[i] = Mod - 1 - val[i];
            }
        }
        trim();
        return *this;
    }
    friend BigInt operator-(const BigInt &rhs)
    {
        BigInt ret(rhs);
        ret.nega ^= 1;
        return ret;
    }
    BigInt &operator-=(const BigInt &rhs)
    {
        rhs.nega ^= 1;
        *this += rhs;
        rhs.nega ^= 1;
        return *this;
    }
    friend BigInt operator*(const BigInt &lhs, const BigInt &rhs)
    {
        int len = 1;
        BigInt ll = lhs, rr = rhs;
        ll.nega = lhs.nega ^ rhs.nega;
        while (len < 2 * lhs.size() || len < 2 * rhs.size())
            len <<= 1;
        ll.val.resize(len), rr.val.resize(len);
        Complex x1[len], x2[len];
        for (int i = 0; i < len; i++)
        {
            Complex nx(ll[i], 0.0), ny(rr[i], 0.0);
            x1[i] = nx;
            x2[i] = ny;
        }
        fft(x1, len, 1);
        fft(x2, len, 1);
        for (int i = 0; i < len; i++)
            x1[i] = x1[i] * x2[i];
        fft(x1, len, -1);
        for (int i = 0; i < len; i++)
            ll[i] = int(x1[i].x + 0.5);
        for (int i = 0; i < len; i++)
        {
            ll[i + 1] += ll[i] / Mod;
            ll[i] %= Mod;
        }
        ll.trim();
        return ll;
    }
    friend BigInt operator*(const BigInt &lhs, const Long &x)
    {
        BigInt ret = lhs;
        bool negat = (x < 0);
        Long xx = (negat) ? -x : x;
        ret.nega ^= negat;
        ret.val.push_back(0);
        ret.val.push_back(0);
        for (int i = 0; i < ret.size(); i++)
            ret[i] *= xx;
        for (int i = 0; i < ret.size(); i++)
        {
            ret[i + 1] += ret[i] / Mod;
            ret[i] %= Mod;
        }
        ret.trim();
        return ret;
    }
    BigInt &operator*=(const BigInt &rhs)
    {
        return *this = *this * rhs;
    }
    BigInt &operator*=(const Long &x)
    {
        return *this = *this * x;
    }
    friend BigInt operator/(const BigInt &lhs, const BigInt &rhs)
    {
        static std::vector<BigInt> powTwo{BigInt(1)};
        static std::vector<BigInt> estimate;
        estimate.clear();
        if (absComp(lhs, rhs) < 0)
            return BigInt();
        BigInt cur = rhs;
        int cmp;
        while ((cmp = absComp(cur, lhs)) <= 0)
        {
            estimate.push_back(cur), cur += cur;
            if (estimate.size() >= powTwo.size())
                powTwo.push_back(powTwo.back() + powTwo.back());
        }
        if (cmp == 0)
            return BigInt(powTwo.back().val, lhs.nega ^ rhs.nega);
        BigInt ret = powTwo[estimate.size() - 1];
        cur = estimate[estimate.size() - 1];
        for (int i = estimate.size() - 1; i >= 0 && cmp != 0; --i)
            if ((cmp = absComp(cur + estimate[i], lhs)) <= 0)
                cur += estimate[i], ret += powTwo[i];
        ret.nega = lhs.nega ^ rhs.nega;
        return ret;
    }
    friend BigInt operator/(const BigInt &num, const Long &x)
    {
        bool negat = (x < 0);
        Long xx = (negat) ? -x : x;
        BigInt ret;
        Long k = 0;
        ret.val.resize(num.size());
        ret.nega = (num.nega ^ negat);
        for (int i = num.size() - 1; i >= 0; i--)
        {
            ret[i] = (k * Mod + num[i]) / xx;
            k = (k * Mod + num[i]) % xx;
        }
        ret.trim();
        return ret;
    }
    bool operator==(const BigInt &rhs) const
    {
        return nega == rhs.nega && val == rhs.val;
    }
    bool operator!=(const BigInt &rhs) const
    {
        return nega != rhs.nega || val != rhs.val;
    }
    bool operator>=(const BigInt &rhs) const
    {
        return !(*this < rhs);
    }
    bool operator>(const BigInt &rhs) const
    {
        return !(*this <= rhs);
    }
    bool operator<=(const BigInt &rhs) const
    {
        if (nega && !rhs.nega)
            return true;
        if (!nega && rhs.nega)
            return false;
        int cmp = absComp(*this, rhs);
        return nega ? cmp >= 0 : cmp <= 0;
    }
    bool operator<(const BigInt &rhs) const
    {
        if (nega && !rhs.nega)
            return true;
        if (!nega && rhs.nega)
            return false;
        return (absComp(*this, rhs) < 0) ^ nega;
    }
    void swap(const BigInt &rhs) const
    {
        std::swap(val, rhs.val);
        std::swap(nega, rhs.nega);
    }
};
int w[10010];
int id=0;
map<int,BigInt> mp;
BigInt te;
BigInt po[10010];
BigInt find(int lenth)
{
    if(mp.find(lenth)!=mp.end())return mp[lenth];
    return mp[lenth]=find(lenth-2)*2ll;
}
BigInt dfs(int cur,BigInt tr)
{
    //cout<<cur<<" "<<tr<<endl;
    BigInt res=0ll;
    if(tr>te)return 0ll;

    if(cur<=id/2)return 1ll;

    if(w[cur]==1)
    {
        res+=find(2*cur-id);
        //cout<<res<<endl;
        res+=dfs(cur-1,tr+po[cur-1]+(id-cur==cur-1?0ll:po[id-cur]));
    }
    else
    {
        res+=dfs(cur-1,tr);
    }
    return res;
}

int main()
{
    BigInt tem;
    cin>>tem;
    if(tem==1ll)
    {
        cout<<1<<endl;
        return 0;
    }
    te=tem;
    while(tem!=0ll)
    {
        auto t=tem/2ll;
        if(t*2ll==tem)w[++id]=0;
        else w[++id]=1;
        tem=t;
    }
    mp[1]=1ll,mp[2]=1ll,mp[0]=0ll;;
    BigInt ans=0ll;
    po[0]=1ll;
    for(int i=1;i<id;i++)
    {
        ans+=find(i);
        po[i]=po[i-1]*2ll;
        //cout<<ans<<endl;
    }
    ans+=dfs(id-1,po[id-1]+1ll);
    cout<<ans<<endl;
    return 0;
}
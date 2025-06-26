/* -mod <= x < 2 * mod */
using LL = long long;
int norm(int x) {
    if(x < 0) x += mod;
    if(x >= mod) x -= mod;
    return x;
}
template<class _T>
_T power(_T a, int n) {
    _T res = 1;
    for(; n; n >>= 1, a *= a)
        if(n & 1) res *= a
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const { return x; }
    Z operator - () const {
        return Z(norm(mod - x));
    }
    Z inv() const {
        return power(*this, mod - 2);
    }
    Z& operator *= (const Z &rhs) {
        x = LL(x) * rhs.x % mod; return *this;
    }
    Z& operator += (const Z &rhs) {
        x = norm(x + rhs.x); return *this;
    }
    Z& operator -= (const Z &rhs) {
        x = norm(x - rhs.x); return *this;
    }
    Z& operator /= (const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator * (const Z &L, const Z &R) {
        Z res = L; res *= R; return res;
    }
    friend Z operator + (const Z &L, const Z &R) {
        Z res = L; res += R; return res;
    }
    friend Z operator - (const Z &L, const Z &R) {
        Z res = L; res -= R; return res;
    }
    friend Z operator / (const Z &L, const Z &R) {
        Z res = L; res /= R; return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        LL v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
}; //1.mod be int 
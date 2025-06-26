int qmi(int a, int k, int p){
    int res = 1ll;
    while (k) {
        if (k & 1ll) res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}
int F[N], inv[N], Finv[N];
void init(int n){
   F[0] = Finv[0] = inv[1] = 1ll;
   for(int i=2;i<=n;i++)  inv[i] = (mod - mod / i) * 1ll * inv[mod % i] % mod;
   for(int i=1;i<=n;i++){
      F[i] = F[i - 1] * 1ll * i % mod;
      Finv[i] = Finv[i - 1] * 1ll * inv[i] % mod;
   }
}
int C(int n, int m){
   if (m < 0 || n < 0 || n < m) return 0;
   return F[n] * 1ll * Finv[n - m] % mod * Finv[m] % mod;
}
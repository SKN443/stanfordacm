// tinh giai thua
ll f[MAXN];

ll nCr(int n, int r){
    return ((f[n] * powmod(f[r], MOD - 2)) % MOD * powmod(f[n - r], MOD - 2)) % MOD;
}

// calculate n-th bernoulli number mod MOD, with 2-th BerN = -1/2, complexity O(n^2)
ll BerN(ll n){
    vector<ll> a = {};
    for (int m = 0; m <= n; m++){
        a.pb(powmod(m + 1, MOD - 2));
        for (int j = m; j >= 1; j--)
            a[j - 1] = j * (a[j - 1] - a[j] + MOD) % MOD;
    }
    return a[0];
}
// calculate (1^p + 2^p + ... + n^p) mod MOD, complexity O(p^3)
ll Cal(ll n, ll p){
    ll res = 0;
    for (int j = 0; j <= p; j++)
        (res += powmod(MOD - 1, j) * nCr(p + 1, j) % MOD * BerN(j) % MOD * powmod(n + 1, p + 1 - j)) %= MOD;
    return res * powmod(p + 1, MOD - 2) % MOD;
}

int main(){
    f[0] = 1;
    for (int i = 1; i < MAXN; i++)
        (f[i] = f[i - 1] * i) %= MOD;
    int n = 27929, r = 189;
    cout << Cal(n, r) << endl;
    ll res = 0;
    for (int i = 1; i <= n; i++)
        (res += powmod(i, r)) %= MOD;
    cout << res;
}

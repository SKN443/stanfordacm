class BIT2D {
    vector<vector<ll>> a;

public:

    void init() {
        a.resize(N, vector<ll>(N));
    }

    void update(ll x, ll y, ll val) {
        if (x == 0 || y == 0) return;
        for(int i = x; i < N; i += i & -i)
            for(int j = y; j < N; j += j & -j)
                a[i][j] += val;
    }

    ll get(ll x, ll y) {
        if (x == 0 || y == 0) return 0;
        ll ans=0;
        for(int i = x; i > 0; i -= i & -i)
            for(int j = y; j > 0; j -= j & -j)
                ans += a[i][j];
        return ans;
    }
} BIT;

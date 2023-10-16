#include <bits/stdc++.h>

#define For(i, a, b) for(ll i=a; i<=b; i++)
#define Fod(i, a, b) for(ll i=a; i>=b; i--)
#define Sc(x) scanf("%lld", &x)
#define p_b(x) push_back(x)
#define ha "mincost"

using namespace std;

typedef long long ll;

const ll N = 109,
INF = 1e10;

ll n, m, k, s, t, f[N][N], d[N][N], c[N][N], u, v, luong, w, doi[N*N*N];
vector <vector <ll> > vertex(N);

ll cost[N], Truy[N];
bool kt[N];

bool Timluong() {
	For(i, 1, n) {
		kt[i] = 0;
		cost[i] = INF;
	}
	ll i = 1, j = 1;
	doi[1] = s;
	cost[s] = 0;
	Truy[s] = 0;

	while (i <= j) {
		u = doi[i];
		i++;
		kt[u] = 0;

		For(z, 0, vertex[u].size() - 1) {
			v = vertex[u][z];
			if (c[u][v] > f[u][v] && cost[v] > cost[u] + (f[u][v] >= 0? d[u][v] : -d[u][v])) {
				cost[v] = cost[u] + (f[u][v] >= 0? d[u][v] : -d[u][v]);
				Truy[v] = u;
				if (!kt[v]) {
					kt[v] = 1;
					doi[++j] = v;
				}
			}
		}
	}

	return (cost[t] != INF);
}

ll dayhang(ll x) {
	v = t; u = Truy[v];
	ll tam = x;
	while (v != s) {
		if (f[u][v] < 0) tam = min(tam, -f[u][v]);
		else tam = min(tam, c[u][v] - f[u][v]);
		v = u; u = Truy[v];
	}

	v = t; u = Truy[v];
	while (v != s) {
		f[u][v] += tam;
		f[v][u] -= tam;
		v = u; u = Truy[v];
	}

	return tam;
}

int main() {
	Sc(n); Sc(m); Sc(k); Sc(s); Sc(t);
	///n: so dinh, m: so canh, k: so hang hoa, s->t
	For(i, 1, m) {
	    ///u -> v & v -> u: w la chi phi, luong la kha nang thong qua
		Sc(u); Sc(v); Sc(w); Sc(luong);
		vertex[u].push_back(v);
		vertex[v].push_back(u);
		c[v][u] = c[u][v] = luong;
		d[u][v] = d[v][u] = w;
	}

	while (Timluong()) {
		k -= dayhang(k);
		if (!k) break;
	}

	if (k > 0) {
		cout <<-1;
		return 0;
	}

	ll kq = 0;
	For(i, 1, n)
		For(j, 1, n) if (f[i][j] > 0) kq += (f[i][j] * d[i][j]);
	cout <<kq <<endl;
	For(i, 1, n)
		For(j, 1, n) if (f[i][j] > 0) cout <<i <<" " <<j <<" " <<f[i][j] <<endl;
		cout <<"0 0 0";
}

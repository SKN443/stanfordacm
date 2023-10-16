#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

struct cung
{
    int to, cap, flow;
};

vector <cung> E;
int n, m, s, t, D[MAXN];
vector <int> adj[MAXN];

int incFlow(int u, int mi)
{
    if (u == t) return mi;
    for (int i: adj[u])
    {
        int v = E[i].to, c = E[i].cap, f = E[i].flow;
        if (D[v] == D[u] + 1 && c > f)
        {
            int df = incFlow(v, min(mi, c - f));
            if (df > 0)
            {
                E[i].flow += df;
                E[i ^ 1].flow -= df;
                return df;
            }
        }
    }
    return 0;
}

bool check()
{
    for (int i = 1; i <= n; ++i) D[i] = INT_MAX;
    D[s] = 0;
    queue <int> Q;
    Q.push(s);
    while (Q.size())
    {
        int u = Q.front(); Q.pop();
        if (u == t) return 1;
        for (int i: adj[u])
        {
            int v = E[i].to, f = E[i].flow, c = E[i].cap;
            if (D[v] > D[u] + 1 && c > f)
            {
                D[v] = D[u] + 1;
                Q.push(v);
            }
        }
    }
    return 0;
}

int main()
{
//    freopen("TEST.INP", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> s >> t;
    while (m--)
    {
        int u, v, c;
        /// u-->v: kha nang thong qua la c
        cin >> u >> v >> c;
        adj[u].push_back(E.size());
        E.push_back({v, c, 0});
        adj[v].push_back(E.size());
        E.push_back({u, 0, 0});
    }

    int ans = 0;
    while (check())
    {
        int df;
        do
        {
            ans += df = incFlow(s, INT_MAX);
        } while (df > 0);
    }

    cout << ans;
    return 0;
}

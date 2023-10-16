int n, m, w[MAXN];
vector<vector<int>> edge(MAXN);
 
int res = 0;
 
void BronKerbosch(set<int> R, set<int> P, set<int> X, int gold = 0){
    if (P.empty() && X.empty()) {
        res = max(res, gold);
    }
    set<int> P_copy = P;
    for (int v : P_copy){
        set<int> R1 = R, P1 = {}, X1 = {};
        if (R.find(v) == R.end()) gold += w[v];
        R1.insert(v);
        for (int u : edge[v])
            if (P.find(u) != P.end()) P1.insert(u);
        for (int u : edge[v])
            if (X.find(u) != X.end()) X1.insert(u);
        BronKerbosch(R1, P1, X1, gold);
        gold -= w[v];
        X.insert(v);
        P.erase(v);
    }
}
int main(){
    while (cin >> n >> m){
        set<int> P;
        res = 0;
        for (int i = 1; i <= n; i++)
            P.insert(i);
        for (int i = 1; i <= n; i++){
            cin >> w[i];
            res = max(res, w[i]);
            edge[i].clear();
        }
        for (int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            edge[u].pb(v);
            edge[v].pb(u);
        }
        BronKerbosch({}, P, {}, 0);
        cout << res << endl;
    }
}
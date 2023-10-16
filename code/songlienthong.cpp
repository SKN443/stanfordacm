// Danh sach ke
typedef vector<vector<int>> dsk;

#define N 30001

// Cau truc disjoint-sets
int root[N];
int find(int u) {
    if (root[u] != u) root[u] = find(root[u]);
    return root[u];
}

bool visited[N];
int active[N];
vector<int> stack;

void dfs(int u, const dsk &ke) {
    visited[u] = true;
    root[u] = u;
    stack.push_back(u);

    for (int v: ke[u]) if (visited[v]) {
        v = find(active[v]);
        while (stack.back() != v) {
            root[find(stack.back())] = v;
            stack.pop_back();
        }
    }

    for (int v: ke[u]) if (!visited[v]) {
        active[u] = v;
        dfs(v, ke);
    }

    if (stack.back() == u) stack.pop_back();
}

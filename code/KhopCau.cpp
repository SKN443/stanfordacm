vector<vector<int>> graph;
vector<int> pre, low;  // -1 unvisited
int timer;


void dfs(int v, int parent = -1) {
    low[v] = pre[v] = timer;
    timer++;
    int children = 0;

    for(int w: graph[v]) {
        if(w == parent) continue;  // skip parent edge

        if(pre[w] != -1){  // forward & back edges
            low[v] = min(low[v], pre[w]);
            continue;
        }

        // tree edges
        dfs(w, v);
        low[v] = min(low[v], low[w]);

        if (pre[v] < low[w]){
            // {v, w} is a bridge
        }
        if (pre[v] <= low[w] && parent != -1){
            // v is an articulation point
        }

        children++;
    }

    if(parent == -1 && children > 1){ // v is root and has at least two children
        // v is an articulation point
    }
}

void find_cutpoints(){
    int n = graph.size();
    pre.assign(n, -1);
    low.assign(n, -1);
    timer = 0;
    for(int i = 0; i < n; i++){
        if(pre[i] == -1) dfs(i);
    }
}

const int MAXN = 1e5 + 7;

struct Node
{
	int lf, rt, val, lazy;
	Node() {}
	Node(int val, int lazy, int lf, int rt): val(val), lazy(lazy), lf(lf), rt(rt) {}
};

int nver;
int nNode;
pair <int, int> b[MAXN], a[MAXN];
int n, q, ver[MAXN], D[MAXN];
Node it[MAXN * 100];

void lazyProp(int nodeId, int l, int r)
{
	int t = it[nodeId].lazy;
	it[nodeId].lazy = 0;
	it[nodeId].val += t * (r - l + 1);
	if (l != r)
	{
		it[it[nodeId].lf].lazy += t;
		it[it[nodeId].rt].lazy += t;
	}
}

int update(int l, int r, int i, int j, int v, int oldId)
{
	lazyProp(oldId, l, r);
	if (i > r || j < l) return oldId;

	if (i <= l && j >= r) 
	{
		++nNode;
		int lfX = l == r ? 0 : it[oldId].lf, rtX = l == r ? 0 : it[oldId].rt;
		it[nNode] = Node(it[oldId].val + v * (r - l + 1), 0, lfX, rtX);
		if (l != r)
		{
			it[lfX].lazy += v;
			it[rtX].lazy += v;
		}
		return nNode;
	}

	int mid = (l + r) >> 1;
	int cur = ++nNode;

	it[cur].lf = update(l, mid, i, j, v, it[oldId].lf);
	it[cur].rt = update(mid + 1, r, i, j, v, it[oldId].rt);
	it[cur].val = it[it[cur].lf].val + it[it[cur].rt].val;

	return cur;
}

int get(int nodeId, int l, int r, int i, int j)
{
	lazyProp(nodeId, l, r);
	if (i > r || j < l) return 0;
	if (i <= l && j >= r) return it[nodeId].val;
	int mid = (l + r) >> 1;
	return get(it[nodeId].lf, l, mid, i, j) + get(it[nodeId].rt, mid + 1, r, i, j);
}
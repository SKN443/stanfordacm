#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e5 + 7;

int main()
{
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    vector <int> p(n), c(n);
    {
        vector <pair <char, int> > a(n);
        for (int i = 0; i < n; ++i) a[i] = {s[i], i};
        sort(a.begin(), a.end());
        c[p[0] = a[0].second] = 0;
        for (int i = 1; i < n; ++i)
            c[p[i] = a[i].second] = c[p[i - 1]] + (a[i].first != a[i - 1].first);
    }

    for (int k = 0; (1 << k) < n; ++k)
    {
        for (int i = 0; i < n; ++i)
            p[i] = (p[i] - (1 << k) + n) % n;

        {
            vector <int> new_p(n), cnt(n, 0), pos(n, 0);
            for (int x: c) ++cnt[x];
            for (int i = 1; i < n; ++i) pos[i] = pos[i - 1] + cnt[i - 1];
            for (int x: p) new_p[pos[c[x]]++] = x;
            p = new_p;
        }

        {
            vector <int> new_c(n, 0);
            for (int i = 1; i < n; ++i)
            {
                pair <int, int> cur = {c[p[i]], c[(p[i] + (1 << k)) % n]};
                pair <int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
                new_c[p[i]] = new_c[p[i - 1]] + (cur != prev);
            }
            c = new_c;
        }
    }
    for (int i = 0; i < n; ++i) cout << p[i] << ' ';
    cout << '\n';

    vector <int> lcp(n);
    int k = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int pi = c[i], j = p[pi - 1];
        while (s[i + k] == s[j + k]) ++k;
        lcp[pi] = k;
        k = max(0, k - 1);
    }
    for (int i = 1; i < n; ++i) cout << lcp[i] << ' ';
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> a, sz, heavy;
vector<int> tin, tout, euler, ans;
vector<int> freq;

int timer = 0;
int maxFreq = 0;
int bestLabel = INT_MAX;

/* DFS per size, heavy child ed Euler tour */
void dfs_prep(int v) {
    tin[v] = timer;
    euler[timer++] = v;

    sz[v] = 1;
    heavy[v] = -1;
    int mx = 0;

    for (int u : g[v]) {
        dfs_prep(u);
        sz[v] += sz[u];
        if (sz[u] > mx) {
            mx = sz[u];
            heavy[v] = u;
        }
    }

    tout[v] = timer - 1;
}

inline void add_node(int v) {
    int x = a[v];
    int f = ++freq[x];
    if (f > maxFreq || (f == maxFreq && x < bestLabel)) {
        maxFreq = f;
        bestLabel = x;
    }
}

inline void remove_node(int v) {
    freq[a[v]]--;
}

/* Aggiunge o rimuove un intero sottoalbero usando l'Euler tour */
void add_subtree(int v, int delta) {
    for (int i = tin[v]; i <= tout[v]; i++) {
        int u = euler[i];
        if (delta == 1) add_node(u);
        else remove_node(u);
    }
}

void dfs(int v, bool keep) {
    for (int u : g[v]) {
        if (u != heavy[v])
            dfs(u, false);
    }

    if (heavy[v] != -1)
        dfs(heavy[v], true);

    for (int u : g[v]) {
        if (u != heavy[v])
            add_subtree(u, 1);
    }

    add_node(v);
    ans[v] = bestLabel;

    if (!keep) {
        add_subtree(v, -1);
        maxFreq = 0;
        bestLabel = INT_MAX;
    }
}

vector<int> solve(int n, vector<int> p, vector<int> z) {
    a = z;
    g.assign(n, {});
    for (int i = 1; i < n; i++)
        g[p[i]].push_back(i);

    sz.assign(n, 0);
    heavy.assign(n, -1);
    tin.assign(n, 0);
    tout.assign(n, 0);
    euler.assign(n, 0);
    ans.assign(n, 0);
    freq.assign(n, 0);

    dfs_prep(0);
    dfs(0, true);

    return ans;
}


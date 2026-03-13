// Fenwick Tree, or Binary Indexed Tree (BIT) -> sum queries
#include <bits/stdc++.h>
using namespace std;

int n;

int sum(int k, vector<int> &tree)
{
    int s = 0;
    while(k >= 1)
    {
        s += tree[k];
        k -= k&-k;
    }
    return s;
}

void add(int k, int x, vector<int> &tree)
{
    while(k <= n)
    {
        tree[k] += x;
        k += k&-k;
    }
}

int main()
{
    cin >> n;
    vector<int> v(n+1); v[0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }

    vector<int> tree(n+1, 0);
    for(int i = 1; i <= n; ++i) add(i, v[i], tree);

    int l, r; cin >> l >> r;
    cout << sum(r, tree)-sum(l-1, tree) << "\n";
}
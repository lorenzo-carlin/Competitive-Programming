#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define f first
#define s second
const int mod = 1e9+7;

int binary_exp(int base, int exp)
{
    if(exp == 0) return 1;
    if(exp == 1) return base % mod;

    ll tmp = binary_exp(base, exp/2);
    ll ans = (tmp * tmp) % mod;
    if(exp % 2) ans = (ans * base) % mod;

    return ans;
}

struct DSU
{
    int n;
    vector<int> father;

    DSU() {}

    DSU(int _n)
    {
        n = _n;
        father.resize(n);
        for(int i = 0; i < n; ++i) father[i] = i;
    }

    int find(int node)
    {
        if(father[node] != node) father[node] = find(father[node]);
        return father[node];
    }

    bool merge(int a, int b)
    {
        int rA = find(a);
        int rB = find(b);
        if(rA == rB) return false;
        father[rB] = rA;
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int r, c, n; cin >> r >> c >> n;
    DSU d = DSU(n);

    map<int,vector<int>> col, rig, di1, di2;
    for(int i = 0, a, b; i < n; ++i)
    {
        cin >> a >> b;
        col[b].push_back(i);
        rig[a].push_back(i);
        di1[a+b].push_back(i);
        di2[a-b].push_back(i);
    }

    int groups = n;
    for(auto x: col)
    {
        int st = x.second.front();
        for(int i = 1; i < x.second.size(); ++i) if(d.merge(st, x.second[i])) groups--;
    }
    for(auto x: rig)
    {
        int st = x.second.front();
        for(int i = 1; i < x.second.size(); ++i) if(d.merge(st, x.second[i])) groups--;
    }
    for(auto x: di1)
    {
        int st = x.second.front();
        for(int i = 1; i < x.second.size(); ++i) if(d.merge(st, x.second[i])) groups--;
    }
    for(auto x: di2)
    {
        int st = x.second.front();
        for(int i = 1; i < x.second.size(); ++i) if(d.merge(st, x.second[i])) groups--;
    }

    cout << binary_exp(2, groups) << "\n";
}
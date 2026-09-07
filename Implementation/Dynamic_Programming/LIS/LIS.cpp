#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> LIS(vector<int> a)
{
    int n = a.size();
    const int INF = 1e9;
    vector<int> v(n+1, INF);
    v[0] = -INF;
    vector<int> idx(n+1, INF);
    idx[0] = -INF;
    vector<int> p(n, -INF);
    for(int i = 0; i < n; ++i)
    {
        int l = upper_bound(begin(v), end(v), a[i]) - begin(v);
        if(v[l-1] < a[i] && a[i] < v[l])
        {
            v[l] = a[i];        // v[l] = valore
            idx[l] = i;         // idx[l] = indice
            p[i] = idx[l-1];    // p[i] = indice del precedente nella LIS
        }
    }

    // reconstructing the solution
    vector<int> sol;
    int last = -1, len = 0;
    for(int l = 1; l <= n; ++l)
    {
        if(v[l] != INF)
        {
            last = idx[l];
            len = l;
        }
    }
    sol.push_back(a[last]);
    len--;

    while(len--)
    {
        last = p[last];
        sol.push_back(a[last]);
    }

    reverse(begin(sol), end(sol));
    return sol;

    /*
    int ans = 0;
    for(int l = 0; l <= n; ++l)
    {
        if(v[l] < INF) ans = l;
    }
    return ans;
    */
}

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i;

    vector<int> sol = LIS(v);
    for(int el: sol) cout << el << " ";
    cout << "\n";
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // INPUT
    int n, m, k; cin >> n >> m >> k;
    bool cond = true;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if(a[i] <= 0) cond = false;
    }
    for(int i = 0; i < m; ++i) cin >> b[i];

    // PREFIX SUMS
    vector<ll> pa(n), pb(m);
    pa[0] = a[0]; pb[0] = b[0];

    // ASSOCIA AD UN VALORE PRESENTE IN PB IL CORRISPETTIVO INDICE
    map<ll,ll> mp; mp[pb[0]] = 0;

    for(int i = 1; i < n; i++) pa[i] = pa[i-1] + a[i];
    for(int i = 1; i < m; i++)
    {
        pb[i] = pb[i-1] + b[i];
        mp[pb[i]] = i;
    }

    if(pa.back() != pb.back())
    {
        cout << "-1\n";
        return 0;
    }

    if(cond) // TWO-POINTERS
    {
        int l = 0, r = 0;
        int sol = 1;
        vector<pair<ll,ll>> ans;
        for(; l < n; l++)
        {
            while(r < m && pb[r] < pa[l]) r++;
            if(pb[r] == pa[l])
            {
                sol++;
                ans.push_back({l, r});
            }
        }

        if(sol < k) cout << "-1\n";
        else
        {
            for(int j = 0; j < k-1; j++) cout << ans[j].first+1 << " ";
            cout << "\n";
            for(int j = 0; j < k-1; j++) cout << ans[j].second+1 << " ";
            cout << "\n";
        }
    } else
    {
        // {VAL, IND} DI OGNI ELEMENTO DI PA CHE HA UN ELEMENTO UGUALE IN PB
        vector<pair<ll,ll>> vv;
        for(int i = 0; i < n; i++)
            if(mp.count(pa[i]))
                vv.push_back({pa[i], i});

        // LIS
        int sz = vv.size();
        vector<ll> v(sz+1, INF);
        v[0] = -INF;
        vector<ll> idx(sz+1, INF);
        idx[0] = -INF;
        vector<ll> p(sz, -INF);
        for(int i = 0; i < sz; ++i)
        {
            int l = upper_bound(begin(v), end(v), vv[i].first) - begin(v);
            if(v[l-1] < vv[i].first && vv[i].first < v[l])
            {
                v[l] = vv[i].first;
                idx[l] = i;
                p[i] = idx[l-1];
            }
        }

        // reconstructing the solution
        vector<pair<ll,ll>> sol;
        int last = -1, len = 0;
        for(int l = 1; l <= sz; ++l)
        {
            if(v[l] != INF)
            {
                last = idx[l];
                len = l;
            }
        }
        if(len < k)
        {
            cout << "-1\n";
            return 0;
        }
        sol.push_back({vv[last].first, vv[last].second});
        len--;
        while(len--)
        {
            last = p[last];
            sol.push_back({vv[last].first, vv[last].second});
        }
        reverse(begin(sol), end(sol));
        
        for(int i = 0; i < k-1; i++) cout << sol[i].second+1 << " ";
        cout << "\n";
        for(int i = 0; i < k-1; i++) cout << mp[sol[i].first]+1 << " ";
        cout << "\n";
    }
}
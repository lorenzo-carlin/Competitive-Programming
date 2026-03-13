#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> values;
vector<pair<ll,ll>> v(40005, {0, 1});
vector<ll> ps(40005, 0);

int compressedIndex(ll num)
{
    return lower_bound(values.begin(), values.end(), num) - values.begin();
}

int main()
{
    ll n, q; cin >> n >> q;

    vector<pair<pair<ll,ll>,ll>> updates(n);
    for(int i = 0; i < n; ++i)
    {
        ll a, b, c; cin >> a >> b >> c;
        values.push_back(a);
        values.push_back(b);
        updates[i] = {{a, b}, c};
    }

    vector<pair<int,int>> queries(q);
    for(int i = 0; i < q; ++i)
    {
        ll a, b; cin >> a >> b;
        values.push_back(a);
        values.push_back(b);
        queries[i] = {a, b};
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    values.push_back(values.back()+1);

    for(auto el: updates)
    {
        v[compressedIndex(el.first.first)].first += el.second;
        v[compressedIndex(el.first.second)].first -= el.second;
    }

    ps[0] = v[0].first;
    v[0].second = values[1] - values[0];
    for(int i = 1; i < values.size()-1; ++i)
    {
        v[i].first += v[i-1].first;
        v[i].second = values[i+1] - values[i];
        ps[i] = (ll) ps[i-1] + v[i].first * v[i].second;
    }
    ps.insert(ps.begin(), 0);

    for(int i = 0; i < q; ++i)
    {
        ll a = compressedIndex(queries[i].first);
        ll b = compressedIndex(queries[i].second);
        ll tot = ps[b] - ps[a];
        cout << tot << "\n";
    }
}
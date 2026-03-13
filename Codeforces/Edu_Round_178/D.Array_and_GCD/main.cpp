#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int DIM = 8e6;
vector<int> primes;

void precalculate()
{
    vector<bool> vis(DIM, true);
    vis[0] = vis[1] = false;
    for(ll i = 2; i < DIM; i++)
    {
        if(!vis[i]) continue;
        for(ll j = i*i; j < DIM; j += i)
            vis[j] = false;

        primes.push_back(i);
    }
}

void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    sort(rbegin(v), rend(v));

    ll sA = 0, sB = 0;
    int idx = n;
    for(int i = 0; i < n; i++)
    {
        sA += v[i];
        sB += primes[i];
        if(sB > sA)
        {
            idx = i;
            break;
        }
    }

    cout << n-idx << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precalculate();

    int t; cin >> t;
    while(t--) solve();
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<int> bins(n, 0); //t
    vector<int> cap(n); //c

    for(auto &i:cap) cin >> i;
    
    ll trash = 0;
    for(int i = 0; i < k; ++i)
    {
        ll b, t; cin >> b >> t;
        if(bins[b] + t > cap[b])
        {
            trash += (cap[b] - bins[b]);
            bins[b] = t;
        } else
        {
            bins[b] += t;
        }
    }
    for(int i = 0; i < n; ++i)
    {
        if(bins[i] != 0)
        {
            trash += (cap[i] - bins[i]);
        }
    }
    cout << trash;
}
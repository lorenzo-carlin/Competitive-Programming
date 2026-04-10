#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<ll> v(n);
    for(ll &i: v) cin >> i;

    if(n == 1)
    {
        cout << v.front() << "\n";
        return;
    } else if(n == 2)
    {
        cout << max(v[0]-v[1], v[1]-v[0]+1) << "\n";
        return;
    }

    ll sumP = 0, sumD = 0;
    for(int i = 0; i < n; i++)
    {
        if(i & 1) sumD += v[i];
        else sumP += v[i];
    }

    vector<ll> prec(n);
    for(int i = 0; i < n; i++)
    {
        if(i & 1) prec[i] = i + 2*v[i];
        else prec[i] = i - 2*v[i];
    }

    vector<ll> mxD(n+1, -1e18), mxP(n+1, -1e18);
    for(int i = n-1; i >= 0; i--)
    {
        mxD[i] = mxD[i+1];
        mxP[i] = mxP[i+1];

        if(i & 1) mxD[i] = max(mxD[i], prec[i]);
        else mxP[i] = max(mxP[i], prec[i]);
    }

    ll mxx = ((n & 1) ? (n-1) : (n-2));
    for(int i = 0; i < n; i++)
    {
        if(i & 1) mxx = max(mxx, 2*v[i]-i + mxP[i+1]);
        else mxx = max(mxx, mxD[i+1] - (i + 2*v[i]));
    }

    cout << mxx+(sumP-sumD) << "\n";
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}

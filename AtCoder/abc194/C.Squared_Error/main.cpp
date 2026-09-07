#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int MAX = 401;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<ll> v(MAX, 0);
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        v[x+200]++;
    }

    ll ans = 0;
    for(int i = 0; i < MAX-1; ++i)
    {
        for(int j = i+1; j < MAX; ++j)
        {
            int n1 = i-200;
            int n2 = j-200;
            ans += ((n1-n2)*(n1-n2)*v[i]*v[j]);
        }
    }

    cout << ans << "\n";
}
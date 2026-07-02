#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll r; cin >> r;
    int n; cin >> n;

    vector<ll> v(n);
    for(auto &i: v) cin >> i;

    // parto da SX
    ll idx1 = 0;
    bool touch1 = false;
    for(int i = 0; i < n; i++)
    {
        idx1 += v[i];
        if(idx1 >= r)
        {
            idx1 = r;
            touch1 = true;
        }
        if(idx1 <= 0)
        {
            idx1 = 0;
        }
    }

    // parto da DX
    ll idx2 = r;
    bool touch2 = false;
    for(int i = 0; i < n; i++)
    {
        idx2 += v[i];
        if(idx2 >= r)
        {
            idx2 = r;
        }
        if(idx2 <= 0)
        {
            idx2 = 0;
            touch2 = true;
        }
    }

    if(touch1) cout << idx1 << "\n";
    else if(touch2) cout << idx2 << "\n";
    else cout << "uncertain\n";
}

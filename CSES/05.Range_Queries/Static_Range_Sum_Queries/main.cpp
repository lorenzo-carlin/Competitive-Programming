#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ll n, q; cin >> n >> q;
    ll lg[n+1]; lg[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        lg[i] = lg[i/2] + 1;
    }
 
    ll K = lg[n];
    ll st[K+1][n];
 
    vector<ll> array(n);
    for(auto &i: array) cin >> i;
 
    copy(array.begin(), array.end(), st[0]);
 
    for(int i = 1; i <= K; i++)
    {
        for(int j = 0; j + (1 << i) <= n; j++)
        {
            st[i][j] = st[i-1][j] + st[i-1][j + (1 << (i - 1))];
        }
    }
 
    for(int i = 0; i < q; ++i)
    {
        ll L, R; cin >> L >> R; L--; R--;
        ll sum = 0;
        for(int i = K; i >= 0; i--)
        {
            if((1 << i) <= R - L + 1)
            {
                sum += st[i][L];
                L += 1 << i;
            }
        }
        cout << sum << "\n";
    }
}

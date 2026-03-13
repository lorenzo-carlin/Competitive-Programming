#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    vector<ll> pot(19, 1);
    for(int i = 1; i < 19; ++i) pot[i] = pot[i-1]*10;
 
    vector<ll> dig(18, 0);
    for(int i = 1; i < 18; ++i) dig[i] = dig[i-1] + i*(pot[i]-pot[i-1]);
    // for(auto el: dig) cout << el << " ";
    // cout << "\n";
 
    int q; cin >> q;
    while(q--)
    {
        ll k; cin >> k;
 
        int num_dig;
        for(int i = 1; i < 19; ++i)
        {
            if(k <= dig[i])
            {
                num_dig = i;
                break;
            }
        }
 
        // cout << num_dig << "\n";
 
        ll left = pot[num_dig-1], right = pot[num_dig]-1;
        while(left <= right)
        {
            ll med = (left + right) / 2;
            ll st_med = dig[num_dig-1]+(num_dig*(med-pot[num_dig-1]))+1;
            if(st_med <= k)
            {
                left = med+1;
            } else
            {
                right = med-1;
            }
        }
        ll num = right;
        ll st_num = dig[num_dig-1]+(num_dig*(num-pot[num_dig-1]))+1;
        // cout << num << "\n";
        string s = to_string(num);
        // cout << s << "\n";
        cout << s[k-st_num] << "\n";
    }
}

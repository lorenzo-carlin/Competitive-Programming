#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll n, t;
vector<ll> v;
 
bool possible(ll med)
{
    ll tot = 0;
    for(auto el: v)
    {
        tot += (med/el);
        if(tot >= t) return true;
    }
    return false;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> t;
    v.resize(n);
    for(auto &i: v) cin >> i;
 
    ll left = 0, right = t*(*max_element(begin(v), end(v)))+1;
    while(left < right)
    {
        ll med = (left + right) / 2;
 
        if(possible(med))
        {
            // cout << med << " True\n";
            right = med;
        } else
        {
            // cout << med << " False\n";
            left = med+1;
        }
    }
 
    if(!possible(left)) cout << left+1 << "\n";
    else cout << left << "\n";
 
}

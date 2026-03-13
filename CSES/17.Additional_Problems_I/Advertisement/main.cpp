#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n; cin >> n;
    vector<ll> v(n);
    for(auto &i:v) cin >> i;
 
    vector<ll> st(n);
    stack<pair<ll,ll>> sx;
    for(int i = 0; i < n; ++i)
    {
        while(!sx.empty() && sx.top().first >= v[i]) sx.pop();
        if(!sx.empty())
        {
            st[i] = sx.top().second;
        } else
        {
            st[i] = -1;
        }
        sx.push({v[i], i});
    }
 
    vector<ll> fn(n);
    stack<pair<ll,ll>> dx;
    for(int i = n-1; i >= 0; --i)
    {
        while(!dx.empty() && dx.top().first >= v[i]) dx.pop();
        if(!dx.empty())
        {
            fn[i] = dx.top().second;
        } else
        {
            fn[i] = n;
        }
        dx.push({v[i], i});
    }
 
    ll sum = 0;
    for(int i = 0; i < n; ++i)
    {
        ll area = (fn[i]-st[i]-1)*v[i];
        if(area > sum) sum = area;
    }
 
    cout << sum << "\n";
}

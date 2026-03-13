#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n; cin >> n;
    ll t = n*(n+1)/2;
    if(t % 2)
    {
        cout << "NO\n";
    } else
    {
        ll target = t/2;
        vector<ll> a, b;
        ll curr = 0;
        for(int i = n; i > 0; i--)
        {
            if(curr + i <= target)
            {
                curr += i;
                a.push_back(i);
            } else
            {
                b.push_back(i);
            }
        }
        if(curr == target)
        {
            cout << "YES\n";
            cout << a.size() << "\n";
            for(auto el: a) cout << el << " ";
            cout << "\n";
            cout << b.size() << "\n";
            for(auto el: b) cout << el << " ";
            cout << "\n";
        } else
        {
            cout << "NO\n";
        }
    }
}
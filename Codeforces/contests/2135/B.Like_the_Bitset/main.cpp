#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k; cin >> n >> k;
    int mx = 0, cur = 0;
    string s; cin >> s;

    bool possible = true;

    int uno = 0, zero = 0;
    for(int i = 0; i < k; ++i)
    {
        if(s[i] == '1') uno++;
        else zero++;
    }
    if(zero == 0) possible = false;

    for(int i = k; i < n; ++i)
    {
        if(s[i] == '1') uno++;
        else zero++;
        if(s[i-k] == '1') uno--;
        else zero--;
        if(zero == 0) possible = false;
    }

    if(possible)
    {
        cout << "YES\n";
        vector<int> v(n);
        int cnt = n;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '0') v[i] = cnt--;
        }
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '1') v[i] = cnt--;
        }

        for(auto el: v) cout << el << " ";
        cout << "\n";
    } else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}

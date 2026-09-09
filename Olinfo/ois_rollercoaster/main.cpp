#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> v(n);
    vector<bool> motorized(n, false);
    for(auto &i: v) cin >> i;

    for(int i = 0; i < n-2; ++i)
    {
        if((v[i+2] - v[i+1] == v[i+1] - v[i]) && ((v[i+1] - v[i]) > 0))
        {
            motorized[i] = motorized[i+1] = motorized[i+2] = true;
        }
    }

    int last_pick = v[0];
    for(int i = 0; i < n; ++i)
    {
        if(i < n-1 && (motorized[i] && !motorized[i+1]))
        {
            if(v[i+1] >= v[i])
            {
                cout << i << "\n";
                return 0;
            } else
            {
                last_pick = v[i];
            }
        } else if(!motorized[i] && (i > 0 && i < n-1))
        {
            if(v[i] >= v[i-1] && v[i] > v[i+1] && v[i] < last_pick)
            {
                last_pick = v[i];
            } else if(v[i] >= last_pick)
            {
                cout << i-1 << "\n";
                return 0;
            }
        }
    }

    cout << n-1 << "\n";
}
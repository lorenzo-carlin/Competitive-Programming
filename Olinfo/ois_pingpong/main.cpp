#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string def = "__________";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        vector<pair<int,int>> sol;
        int a, b; cin >> a >> b;
        if(a > 53 || b > 52)
        {
            cout << "-1 -1\n";
            continue;
        }
        int vic_a = min(3, a / 11), vic_b = min(2, b / 11);
        if(vic_a < 3)
        {
            cout << "-1 -1\n";
            continue;
        }
        a -= 11*vic_a;
        b -= 11*vic_b;

        for(int i = 0; i < vic_b; ++i)
        {
            sol.push_back({min(a, 10), 11});
            a -= min(a, 10);
        }

        for(int i = 0; i < vic_a; ++i)
        {
            sol.push_back({11, min(b, 10)});
            b -= min(b, 10);
        }
        if(a > 0 || b > 0)
        {
            cout << "-1 -1\n";
            continue;
        }
        for(auto el: sol) cout << el.first << " " << el.second << "\n";
    }
}
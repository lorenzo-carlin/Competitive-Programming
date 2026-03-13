#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int cas = 1; cas <= t; ++cas)
    {
        int n; cin >> n;
        vector<int> v(n);
        for(int &i: v) cin >> i;

        int sol = 1;
        for(int i = 1; i < n; ++i)
        {
            bool cond = true;
            for(int j = 0; j < n; ++j)
            {
                if(!cond) break;
                if(v[(i+j)%n] != v[j]) cond = false;
            }
            if(cond) sol++;
        }

        cout << "Case #" << cas << ": " << sol << "\n";
    }
}
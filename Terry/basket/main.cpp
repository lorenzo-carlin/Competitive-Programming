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
        vector<int> a(n), b(n);
        for(int &i: a) cin >> i;
        for(int &i: b) cin >> i;

        int sol = 0;
        int l = 0, r = 0;
        for(; l < n; ++l)
        {
            while(r < n && b[r] < a[l]) r++;
            if(b[r] == a[l])
            {
                sol++;
                r++;
            }
        }

        cout << "Case #" << cas << ": " << sol << "\n";
    }
}
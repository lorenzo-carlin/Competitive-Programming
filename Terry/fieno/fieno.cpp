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

        int mx = -1, mx_ind = -1;
        for(int i = 1; i < n-1; ++i)
        {
            if(v[i] > v[i-1] && v[i] > v[i+1])
            {
                int tmp = min(v[i] - v[i-1], v[i] - v[i+1]);
                if(tmp > mx)
                {
                    mx = tmp;
                    mx_ind = i;
                }
            }
        }

        cout << "Case #" << cas << ": " << mx_ind << "\n";
    }

}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k; cin >> n >> m >> k;
    vector<int> v(n);
    for(auto &i: v) cin >> i;
    v.push_back(k);

    int until = m, sol = 0;
    for(int i = 0; i < n; ++i)
    {
        if(v[i] <= until && v[i+1] > until)
        {
            sol++;
            until = v[i] + m;
        }
    }

    cout << sol << "\n";
}
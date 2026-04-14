#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        
        vector<int> v(n);
        for(auto &i: v) cin >> i;

        sort(v.begin(), v.end());
        int sol = 0;
        for(int i = 0; i < v.size()/2; ++i)
        {
            sol += (v[v.size()-1-i] - v[i]);
        }
        cout << sol << "\n";
    }
}
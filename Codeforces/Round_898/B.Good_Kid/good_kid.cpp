#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int sol = v[0]+1;
        for(int i = 1; i < n; ++i)
        {
            sol*=v[i];
        }
        cout << sol << "\n";
    }
}
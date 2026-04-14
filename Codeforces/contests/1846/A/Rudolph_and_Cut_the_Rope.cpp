#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<pair<int,int>> v(n);
        int ub = 1e9, lb = 0;
        for(int i = 0; i < n; ++i)
        {
            int a, b; cin >> a >> b;
            v[i] = {a, b};
            if(a+b < ub) ub = a+b;
            if(a-b > lb) lb = a-b;
        }
        int k = lb;
        if(k == 0)
        {
            cout << "0\n";
            continue;
        }
        int sol = 0;
        for(int i = 0; i < n; ++i)
        {
            if((v[i].first >= k && v[i].first > v[i].second) || (v[i].first <= k && v[i].second < v[i].first)) sol++;
        }
        cout << sol << "\n";
    }
}
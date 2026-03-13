#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    stack<pair<int,int>> sol;
    sol.push({1e9, -1});
    for(int i = 0; i < n; ++i)
    {
        while(sol.top().first <= v[i]) sol.pop();
        cout << sol.top().second << " ";
        sol.push({v[i], i});
    }
}
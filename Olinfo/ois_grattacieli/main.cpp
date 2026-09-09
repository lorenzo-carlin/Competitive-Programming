#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i;

    int mx = *max_element(v.begin(), v.end());
    v.insert(v.begin(), mx);
    v.push_back(mx);

    vector<int> ind;
    for(int i = 0; i < v.size(); ++i)
    {
        if(v[i] == mx) ind.push_back(i);
    }

    int tot = 0, l = -1, r = -1;
    for(int i = 0; i < ind.size()-2; ++i)
    {
        if(ind[i+2]-ind[i]+1 > tot || (ind[i+2]-ind[i]+1 == tot && i+2 != n+1))
        {
            tot = ind[i+2]-ind[i]+1;
            l = ind[i];
            r = ind[i+2];
        }
    }
    if(l == 0) tot--;
    if(r == n+1) tot--;
    cout << tot << "\n";


}
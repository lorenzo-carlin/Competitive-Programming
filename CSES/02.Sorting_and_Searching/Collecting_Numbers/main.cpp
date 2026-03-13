#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> v(n);
    for(auto &i: v) cin >> i;

    set<int> s;
    int sol = 1;
    for(int i = n-1; i >= 0; i--)
    {
        if(s.count(v[i]-1)>0) sol++;
        s.insert(v[i]);
    }

    cout << sol << "\n";
}
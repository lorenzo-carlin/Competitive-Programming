#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    vector<int> b(n);
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        s.insert(v[i]);
        if(v[i] == s.size()) b[i] = i;
        else b[i] = s.size();
    }

    for(int el: b) cout << el << " ";
    cout << "\n";
}

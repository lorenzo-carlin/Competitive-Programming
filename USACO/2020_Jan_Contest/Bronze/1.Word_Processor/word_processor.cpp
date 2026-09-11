#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int n, k; cin >> n >> k;
    vector<string> v(n);
    for(auto &i: v) cin >> i;
    int curr = 0;
    for(int i = 0; i < n; ++i)
    {
        if(curr+v[i].size() > k)
        {
            cout << "\n";
            curr = v[i].size();
            cout << v[i];
        } else if(i == 0)
        {
            curr = v[i].size();
            cout << v[i];
        } else
        {
            curr += v[i].size();
            cout << " " << v[i];
        }
    }
}
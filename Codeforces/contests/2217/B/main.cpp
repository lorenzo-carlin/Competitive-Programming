#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    int idx; cin >> idx; idx--;

    int cntSx = 0, cntDx = 0;
    for(int i = idx+1; i < n-1; i++)
    {
        if(v[i] != v[i+1]) cntDx++;
    }
    if(v.back() != v[idx]) cntDx++;
    if(cntDx & 1) cntDx++;
    for(int i = idx-1; i > 0; i--)
    {
        if(v[i] != v[i-1]) cntSx++;
    }
    if(v.front() != v[idx]) cntSx++;
    if(cntSx & 1) cntSx++;

    cout << max(cntSx, cntDx) << "\n";
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}

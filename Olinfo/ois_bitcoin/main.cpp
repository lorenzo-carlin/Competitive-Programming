#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e; cin >> n >> e;
    vector<int> v(n);
    for(auto &i: v) cin >> i;

    double pr = (double) e;
    double curr = pr;
    for(int i = 0; i < n; ++i)
    {
        if(v[i] > 0)
        {
            curr += (double) (v[i]*curr/pr);
        }
        pr += (double) v[i];
    }
    cout << fixed << setprecision(8) << floor(curr*1e8)/1e8 << "\n";
}
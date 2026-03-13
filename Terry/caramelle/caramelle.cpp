#include <bits/stdc++.h>
using namespace std;

int confronto(int mcm, int num)
{
    int tmp = num;
    while(num % mcm != 0)
    {
        num += tmp;
    }
    return num;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int x = 1; x <= t; ++x)
    {
        int n; cin >> n;
        vector<int> v(n);
        for(auto &i:v) cin >> i;
        sort(v.begin(), v.end());
        int mcm = 1;
        for(int i = 0; i < n; ++i)
        {
            mcm = confronto(mcm, v[i]);
        }
        cout << "Case #" << x << ": " << mcm << endl;
    }
}
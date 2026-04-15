#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, d, h; cin >> n >> d >> h;
        vector<double> v(n);
        for(auto &i: v) cin >> i;

        sort(v.rbegin(), v.rend());

        double tot = (double) d*h/2;
        for(int i = 1; i < n; ++i)
        {
            tot += (double) d*h/2;
            if(v[i] + h > v[i-1])
            {
                double h1 = v[i]+h-v[i-1];
                double d1 = (double) d*h1/h;
                tot -= (double) d1*h1/2;
            }
        }

        cout << tot << "\n";
    }
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int x = 1; x <= t; ++x)
    {
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        v.push_back(-1);
        int sum = 0, mx = 0, cons = 0;
        for(auto el:v)
        {
            if(el == -1)
            {
                sum += (cons-1);
                cons = 0;
                if(sum > mx) mx = sum;
                sum = 0;
            } else
            {
                sum += el;
                cons++;
            }
        }
        int prec = 0, mn = 1e9;
        sum = 0, cons = 0;
        for(auto el:v)
        {
            if(el != -1)
            {
                sum += el;
                cons++;
            }
            if(prec == -1)
            {
                sum += (cons-1);
                if(sum < mn) mn = sum;
                sum = el;
                cons = 1;
            }
            prec = el;
        }
        mn--;
        cout << "Case #" << x << ": " << mx << " " << mn << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; ++i)
    {
        int t; cin >> t;
        v[t-1]++;
    }
    for(int i = 0; i < n; ++i)
    {
        if(v[i] == 0)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
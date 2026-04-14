#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int mx = 0, mx_ind = -1;
        for(int i = 0; i < n; ++i)
        {
            int a, b; cin >> a >> b;
            if(a <= 10 && b > mx)
            {
                mx = b;
                mx_ind = i+1;
            }
        }
        cout << mx_ind << "\n";
    }
}
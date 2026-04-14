#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int last = -1e9, sol = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == 'B')
            {
                if(i-last+1 > k)
                {
                    sol++;
                    last = i;
                }
            }
        }
        cout << sol << "\n";
    }
}
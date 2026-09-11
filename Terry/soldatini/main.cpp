#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int x = 1; x <= t; ++x)
    {
        int len; cin >> len;
        string s; cin >> s;
        
        int mx = 0;
        bool cond = false;
        int current = 0, ind = 0;
        for(int i = 0; i < len; ++i)
        {
            if(s[i] == '1')
            {
                current++;
            }
            if(s[i] == '0')
            {
                if(cond)
                {
                    current = i-ind;
                    cond = false;
                }
                current++;
                if(current > mx)
                {
                    mx = current;
                }
                if(s[i+1] == '0')
                {
                    current = 0;
                }
                if(s[i+1] == '1')
                {
                    ind = i+1;
                    cond = true;
                }
            }
            if(current > mx)
            {
                mx = current;
            }
            //cout << "Case #" << x << ": " << mx << "\n";
        }
        cout << "Case #" << x << ": " << mx << "\n";
    }
}
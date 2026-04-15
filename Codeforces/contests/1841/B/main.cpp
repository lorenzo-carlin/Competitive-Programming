#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int q; cin >> q;
        int st = -1, fn = -1, curr = -1;
        bool cond = false;
        for(int i = 0; i < q; ++i)
        {
            cin >> curr;
            if(i == 0)
            {
                st = curr;
            }
            if((cond && curr < fn) || (cond && curr > st) || (i > 1 && curr < fn && curr > st))
            {
                cout << "0";
            } else
            {
                cout << "1";
                if(curr < fn && !cond)
                {
                    cond = true;
                }
                fn = curr;
            }
            
        }
        cout << "\n";
    }
}

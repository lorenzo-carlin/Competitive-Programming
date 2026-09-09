#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin >> N;
    int s[N];
    if(N == 1)
    {
        cin >> s[0];
        cout << -1;
    } else if(N == 2)
    {
        cin >> s[0] >> s[1];
        if((s[0] + s[1]) % 2 == 0)
        {
            cout << s[0] + s[1];
        } else
        {
            cout << -1;
        }
    } else if(N > 2)
    {
        int mx1 = 0, mx2 = 0, mx3 = 0;
        for(int i = 0; i < N; ++i)
        {
            cin >> s[i];
            if(s[i] > mx1)
            {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = s[i];
            } else if(s[i] > mx2)
            {
                mx3 = mx2;
                mx2 = s[i];
            } else if(s[i] > mx3)
            {
                mx3 = s[i];
            } 
        }
        int sm1 = mx1 + mx2;
        int sm2 = mx1 + mx3;
        int sm3 = mx2 + mx3;
        int mx = 0;
        if(sm1 % 2 == 0 && sm1 > mx)
        {
            mx = sm1;
            cout << mx;
        } else if(sm2 % 2 == 0 && sm2 > mx)
        {
            mx = sm2;
            cout << mx;
        } else if(sm3 % 2 == 0 && sm3 > mx)
        {
            mx = sm3;
            cout << mx;
        } else
        {
            cout << -1;
        }
    }
    return 0;
}
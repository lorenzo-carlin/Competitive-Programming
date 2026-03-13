#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // input
    int n, s, r;
    cin >> n >> s >> r;
    vector<int> teams(n, 0);
    for(int i = 0; i < s; ++i)
    {
        int a; cin >> a;
        teams[a-1] = -1;
    }
    for(int i = 0; i < r; ++i)
    {
        int a; cin >> a;
        if(teams[a-1] == -1)
        {
            teams[a-1] = 0;
        } else
        {
            teams[a-1] = 1;
        }
    }

    // algoritmo risolutivo
    for(int i = 0; i < n; ++i)
    {
        if(teams[i] == 0)
        {
            continue;
        }
        if(teams[i] == 1)
        {
            if(i-1 >= 0 && teams[i-1] == -1)
            {
                teams[i] = 0;
                teams[i-1] = 0;
            } else if(i+1 < n && teams[i+1] == -1)
            {
                teams[i] == 0;
                teams[i+1] = 0;
            }
        }
    }

    int cnt = 0;
    for(int i:teams)
    {
        if(i == -1)
        {
            cnt++;
        }
    }

    cout << cnt;
}
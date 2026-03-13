#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> count(int n, vector<int> s, vector<int> p)
{
    vector<array<int,3>> v(n);
    for(int i = 0; i < n; i++)
        v[i] = {s[i], -p[i], i};
    sort(rbegin(v), rend(v));

    int mn1 = 1e9, mn2 = 1e9, idx = -1;
    vector<bool> ottimale(n, false);
    int ottimali = 0;
    vector<int> potenziali(n, -1);

    for(int i = 0; i < n; i++)
    {
        if(-v[i][1] < mn1)
        {
            mn2 = mn1;
            mn1 = -v[i][1];
            idx = v[i][2];
            ottimale[v[i][2]] = true;
            ottimali++;
        } else if(-v[i][1] < mn2)
        {
            mn2 = -v[i][1];
            potenziali[v[i][2]] = idx;
        }
    }

    vector<int> ans(n, ottimali);
    for(int i = 0; i < n; i++)
        ans[i] -= (ottimale[i] == true);
    for(int i = 0; i < n; i++)
        if(potenziali[i] != -1)
            ans[potenziali[i]]++;

    return ans;
}

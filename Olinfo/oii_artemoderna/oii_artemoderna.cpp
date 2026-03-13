#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ordina(int n, vector<int> v, vector<int> &l)
{
    stack<int> s;
    vector<int> ord;
    int ind = 0;
    while(ind < n)
    {
        s.push(v[ind]);
        ind++;
        while(ind < n && v[ind] <= s.top())
        {
            s.push(v[ind]);
            ind++;
        }
        l.push_back(s.size());
        while(!s.empty())
        {
            ord.push_back(s.top());
            s.pop();
        }
    }

    for(int i = 0; i < n-1; ++i) if(ord[i] > ord[i+1]) return false;
    return true;
}
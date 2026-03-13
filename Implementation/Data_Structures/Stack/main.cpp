#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    stack<pair<int,int>> s;
    vector<int> sol(n);
    for(int i = n-1; i >= 0; i--)
    {
        while(!s.empty() && s.top().first >= v[i])
            s.pop();
        sol[i] = (s.empty()) ? (-1) : (s.top().second);
        s.push({v[i], i});
    }
}

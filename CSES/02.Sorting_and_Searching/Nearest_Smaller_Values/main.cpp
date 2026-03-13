#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for(auto &i:v) cin >> i;
    
    stack<pair<int,int>> s;
    s.push({-1,-1});
    for(int i = 0; i < n; ++i)
    {
        while(s.top().first >= v[i])
        {
            s.pop();
        }
        if(s.top().first < v[i])
        {
            if(s.top().first == -1)
            {
                cout << "0 ";
            } else
            {
                cout << s.top().second << " ";
            }
        }
        s.push({v[i], i+1});
    }
}
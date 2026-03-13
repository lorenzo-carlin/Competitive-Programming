#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    map<string,string> teams;
    map<string,int> pnts;
    for(int i = 0; i < n; ++i)
    {
        string a, b;
        cin >> a >> b;
        teams[a] = b;
        pnts[b] = 0;
    }
    for(int i = 0; i < m; ++i)
    {
        string a, b;
        cin >> a >> b;
        int c, d;
        cin >> c >> d;
        if(c == d)
        {
            pnts[teams[a]] += 2;
            pnts[teams[b]] += 2;
        } else if(c > d)
        {
            pnts[teams[a]] += 4;
            pnts[teams[b]]++;
        } else if(d > c)
        {
            pnts[teams[b]] += 4;
            pnts[teams[a]]++;
        }
    }
    pair<string,int> current;
    while(!pnts.empty())
    {
        current.first = "";
        current.second = -1;
        for(auto i:pnts)
        {
            if(i.second>current.second)
            {
                current.second = i.second;
                current.first = i.first;
            }
            if(i.second == current.second && i.first < current.first)
            {
                current.first = i.first;
            }
        }
        cout << current.first << " " << current.second << endl;
        pnts.erase(current.first);
    }
}    
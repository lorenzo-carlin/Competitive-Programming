#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string hello = "hello";
string world = "world";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;
    vector<bool> v;
    string tmp;
    for(int i = 0; i < s.size(); ++i)
    {
        tmp += s[i];

        if(i > 4) tmp.erase(tmp.begin());

        if(tmp == hello) v.push_back(true);
        if(tmp == world) v.push_back(false);
    }

    ll tot = 0, cur = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        if(v[i]) cur++;
        else tot += cur;
    }

    cout << tot << "\n";


    // for(int i = 0; i < h.size(); ++i)
    // {
    //     for(int j = 0; j < w.size(); ++j)
    //     {
    //         if(h[i] < w[j]) tot++;
    //     }
    // }

    // cout << tot << "\n";
}
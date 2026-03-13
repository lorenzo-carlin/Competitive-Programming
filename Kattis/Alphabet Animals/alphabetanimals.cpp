#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);

    string s; cin >> s;
    int n; cin >> n;
    vector<vector<string>> adj(26);
    string notvalid;

    string tmp;
    while(n--)
    {
        cin >> tmp;
        int pos = tmp[0] - 'a';
        adj[pos].push_back(tmp);
    }

    int ind = s.back() - 'a';
    for(auto el: adj[ind])
    {
        if(adj[el.back() - 'a'].empty() || (adj[el.back() - 'a'].size() == 1 && adj[el.back() - 'a'][0] == el))
        {
            cout << el << "!\n";
            notvalid = el;
            return 0;
        }
    }

    if(adj[ind].empty())
    {
        cout << "?\n";
    } else
    {
        for(auto el: adj[ind])
        {
            if(el != notvalid)
            {
                cout << el << "\n";
                break;
            }
        }
    }
}
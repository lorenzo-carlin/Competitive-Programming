#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<string> v(n);
    string buf;
    getline(cin, buf);
    for(int i = 0; i < n; i++)
    {
        getline(cin, v[i]);
    }

    vector<pair<string,int>> ord(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            if(v[i][j] >= 'A' && v[i][j] <= 'Z')
            {
                ord[i] = {v[i].substr(j, v[i].size()-j), i};
                break;
            }
        }
    }

    sort(begin(ord), end(ord));

    for(int i = 0; i < n; i++)
    {
        cout << v[ord[i].second] << "\n";
    }
}

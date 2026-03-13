#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string,int> mp;
    int mx = 0;
    string win;

    int n; cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        mp[s]++;
        if(mp[s] > mx)
        {
            mx = mp[s];
            win = s;
        }
    }

    cout << win << "\n";
}

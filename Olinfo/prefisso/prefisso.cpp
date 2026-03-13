#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;
    int sz = s.size();

    vector<vector<int>> mat(sz, vector<int> (10, 0));

    for(int i = 0; i < sz; ++i)
    {
        mat[i][s[i]-'0']++;
    }

    for(int i = 1; i < n; ++i)
    {
        cin >> s;
        for(int i = 0; i < sz; ++i)
        {
            mat[i][s[i]-'0']++;
        }
    }

    int sol = 0;
    for(int i = 0; i < sz; ++i)
    {
        if(mat[i][s[i]-'0'] == n) sol++;
        else break;
    }

    cout << sol << "\n";
}
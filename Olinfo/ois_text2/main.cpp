#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    int sol[k][26];

    for(int i = 0; i < k; ++i)
    {
        for(int j = 0; j < 26; ++j)
        {
            sol[i][j] = 0;
        }
    }

    vector<string> v(n);
    for(auto &i: v) cin >> i;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < v[i].size(); ++j)
        {
            int ind = v[i][j] - 'a';
            sol[j][ind]++;
        } 
    }

    float mn = 1e9;
    int ind_mn = -1;
    for(int i = 0; i < n; ++i)
    {
        int dist = 0;
        for(int j = 0; j < k; ++j)
        {
            dist += (n - (sol[j][v[i][j]-'a']));
        }
        float tmp = (float) dist / 2;
        if(tmp < mn)
        {
            mn = tmp;
            ind_mn = i;
        }
    }

    cout << ind_mn << "\n";
}
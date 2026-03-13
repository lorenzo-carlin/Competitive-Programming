#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(vector<int> &v)
{
    int uno = 0, due = 0, games = 0;
    for(int i = 0; i < v.size(); i++)
    {
        uno += (v[i] == 1);
        due += (v[i] == 2);

        if(uno >= 4 && uno-due >= 2)
        {
            games++;
            uno = due = 0;
        } else if(due >= 4 && due-uno >= 2)
        {
            games++;
            uno = due = 0;
        }
    }

    return games;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> v(n);
        for(int &i: v) cin >> i;
        int mx = 0;
        for(int i = 0; i < n; i++)
        {
            mx = max(mx, solve(v));
            v.erase(v.begin());
        }
        cout << mx << "\n";
    }
}

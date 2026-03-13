#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int cas = 1; cas <= t; ++cas)
    {
        int n; cin >> n;
        vector<pair<int,int>> v(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> v[i].first;
            v[i].second = i;
        }

        sort(begin(v), end(v), [&] (pair<int,int> a, pair<int,int> b)
        {
            if(a.first != b.first)
            {
                return a.first > b.first;
            } else
            {
                return a.second < b.second;
            }
        });

        vector<int> sol(n, -1);
        for(int i = 0; i < n; ++i)
        {
            // v[i].first := cnt da raggiungere
            // v[i].second := indice dell'elemento in posizione i
            for(int j = n-1, cnt = 0; cnt < v[i].first && j >= 0; j--)
            {
                // j := posizione dentro v
                if(j == i) continue;
                if(sol[v[j].second] == -1)
                {
                    sol[v[j].second] = v[i].second;
                    cnt++;
                }
            }
        }

        cout << "Case #" << cas << ": ";
        for(int i = 0; i < n; ++i)
        {
            cout << sol[i] << " ";
        }
        cout << "\n";
    }
}
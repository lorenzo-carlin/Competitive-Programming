#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;

    // calcolo i valori di dp
    vector<int> dp(n+1);

    auto set_from_x = [&] (int x) -> int
    {
        cout << "? " << x << " " << n << " ";
        for(int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << "\n";
        cout << flush;
        
        int ans; cin >> ans;
        return ans;
    };

    for(int i = 1; i <= n; i++)
    {
        dp[i] = set_from_x(i);
    }

    // trovo lunghezza del path e start del path
    int L = 0, st = -1;
    for(int i = 1; i <= n; i++)
    {
        if(dp[i] > L)
        {
            L = dp[i];
            st = i;
        }
    }

    vector<int> path;
    path.push_back(st);

    // catalogo gli indici per valore di dp
    vector<vector<int>> table(n+1);
    for(int i = 1; i <= n; i++)
    {
        table[dp[i]].push_back(i);
    }

    // funzione per vedere se due archi sono collegati
    auto couple = [&] (int a, int b) -> bool
    {
        cout << "? " << a << " 2 " << a << " " << b << " ";
        cout << "\n";
        cout << flush;

        int ans; cin >> ans;
        if(ans == 2) return true;
        else return false;
    };

    // inizio a costruire il percorso
    for(int i = L-1; i > 0; i--)
    {
        // cerco tra i possibili candidati
        for(int u: table[i])
        {
            if(couple(path.back(), u))
            {
                path.push_back(u);
                break;
            }
        }
    }

    // stampo il percorso
    cout << "! " << L << " ";
    for(int v: path)
    {
        cout << v << " ";
    }
    cout << "\n";
    cout << flush;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}

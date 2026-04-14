#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int &i: a) cin >> i;
    for(int &i: b) cin >> i;
    for(int &i: a) i--;
    for(int &i: b) i--;

    vector<int> associate(n, -1);
    vector<int> pos(n, -1);

    for(int i = 0; i < n; i++)
    {
        if(associate[a[i]] == -1)
        {
            associate[a[i]] = b[i];
            associate[b[i]] = a[i];
        } else if(associate[a[i]] != b[i] || associate[b[i]] != a[i])
        {
            cout << -1 << "\n";
            return;
        }

        pos[a[i]] = i;
    }

    vector<pair<int,int>> moves;

    auto move = [&] (int i, int j) -> void
    {
        moves.push_back({i+1, j+1});

        swap(pos[a[i]], pos[a[j]]);

        swap(a[i], a[j]);
        swap(b[i], b[j]);
    };

    bool found = false;
    for(int i = 0; i < n; i++)
    {
        if(associate[a[i]] == a[i] && found)
        {
            cout << -1 << "\n";
            return;
        } else if(associate[a[i]] == a[i])
        {
            found = true;
        }
    }

    if(n & 1)
    {
        for(int i = 0; i < n; i++)
            if(i != n/2 && associate[a[i]] == a[i])
                move(i, n/2);
    }

    for(int i = 0; i < n/2; i++)
    {
        if(pos[associate[a[i]]] != n-i-1)
        {
            move(pos[associate[a[i]]], n-i-1);
        }
    }

    cout << moves.size() << "\n";
    for(auto el: moves)
        cout << el.first << " " << el.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}

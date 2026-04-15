#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<array<ll,2>> ancors(n);
    for(auto &i: ancors) cin >> i[0] >> i[1];
    ll out = 1000000000;

    // A = (x + y), B = x - y

    ll mx_A = -2e9;
    for(int i = 0; i < n; ++i) mx_A = max(mx_A, ancors[i][0]+ancors[i][1]);
    ll mx_B = -2e9;
    for(int i = 0; i < n; ++i) mx_B = max(mx_B, ancors[i][0]-ancors[i][1]);

    ll delta = 0;       // distanza che aggiungo alla posizione iniziale spostandomi
    ll buffer, t1, t2;  // variabili per l'input

    // mi sposto in alto a destra di +2e9 in entrambe le direzioni
    cout << "? U " << out << "\n";
    cout << flush;
    cin >> buffer;
    cout << "? U " << out << "\n";
    cout << flush;
    cin >> buffer;
    cout << "? R " << out << "\n";
    cout << flush;
    cin >> buffer;
    cout << "? R " << out << "\n";
    cout << flush;
    cin >> t1;

    // ricavo A
    delta = 4e9;
    ll A = t1 + mx_A - delta;

    // mi sposto in basso di 6e9
    cout << "? D " << out << "\n";
    cout << flush;
    cin >> buffer;
    cout << "? D " << out << "\n";
    cout << flush;
    cin >> buffer;
    cout << "? D " << out << "\n";
    cout << flush;
    cin >> buffer;
    cout << "? D " << out << "\n";
    cout << flush;
    cin >> buffer;
    cout << "? D " << out << "\n";
    cout << flush;
    cin >> buffer;
    cout << "? D " << out << "\n";
    cout << flush;
    cin >> t2;

    // ricavo B
    delta = 6e9;
    ll B = t2 + mx_B - delta;

    ll x = (A + B) / 2;
    ll y = (A - B) / 2;

    cout << "! " << x << " " << y << "\n";
    cout << flush;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}

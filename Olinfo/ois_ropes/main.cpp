#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int &i: a) cin >> i;
    for(int &i: b) cin >> i;

    vector<int> mx(n+1, -1);
    int sol = 0;
    for(int i = 0; i < n; ++i)
    {
        if(b[i] > mx[a[i]])
        {
            if(mx[a[i]] != -1) sol += mx[a[i]];
            mx[a[i]] = b[i];
        } else sol += b[i];
    }

    cout << sol << "\n";
}
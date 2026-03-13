#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int quadri(int N, ll M, int V[])
{
    ll sum = 0;
    int l = 0, r = 0;

    while(r < N && sum + V[r] <= M)
    {
        sum += V[r];
        r++;
    }
    int mn = r - l;

    while(r < N)
    {
        sum -= V[l];
        l++;
        while(r < N && sum + V[r] <= M)
        {
            sum += V[r];
            r++;
        }
        mn = min(mn, r - l);
    }
    return mn;
}

int main()
{
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    ll m; cin >> m;

    int v[n];
    for(auto &i: v) cin >> i;

    cout << quadri(n, m, v) << "\n";
}
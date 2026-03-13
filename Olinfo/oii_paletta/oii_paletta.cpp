#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1500000;
int bit[MAX], a[MAX], b[MAX];

int query(int ind)
{
    int tot = 0;
    while(ind >= 0)
    {
        tot += bit[ind];
        ind = (ind&(ind+1))-1;
    }
    return tot;
}

void update(int ind, int N)
{
    while(ind < N)
    {
        bit[ind]++;
        ind = ind|(ind+1);
    } 
}

ll solve(int N)
{
    for(int i = 0; i < N; ++i)
    {
        bit[i] = 0;
        b[a[i]] = i;
    }

    ll sol = 0;

    for(int i = N-1; i >= 0; --i)
    {
        sol += (ll)query(b[i]);
        update(b[i], N);
    }

    return sol;
}

ll paletta_sort(int N, int V[])
{
    for(int i = 0; i < N; ++i) if((V[i]%2) != (i%2)) return -1;

    ll sol = 0;
    for(int i = 0; i < N; i += 2) a[i/2] = V[i]/2;
    sol += solve((N+1)/2);
    for(int i = 1; i < N; i += 2) a[(i-1)/2] = (V[i]-1)/2;
    sol += solve(N/2);

    return sol;
}

int main()
{
    int n; cin >> n;
    int v[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    cout << paletta_sort(n, v) << "\n";

}
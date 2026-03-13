#include <bits/stdc++.h>
using namespace std;

int Trova(int N, int K, int insieme[])
{
    if(K == 1) return 0;
    
    sort(insieme, insieme+N);
    reverse(insieme, insieme+N);

    set<int> s;
    for(int i = 0; i < N; ++i) if(s.count(K*insieme[i]) == 0) s.insert(insieme[i]);

    return s.size();
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k; cin >> n >> k;
    int v[n];
    for(auto &i: v) cin >> i;

    cout << Trova(n, k, v);
}
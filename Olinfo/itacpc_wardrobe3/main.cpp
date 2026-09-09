#include <bits/stdc++.h>
using namespace std;
using ll =  long long;

int main()
{
    int m, k; cin >> m >> k;
    string n; cin >> n;

    // sort di n
    vector<int> cnt(10, 0);
    for(int i = 0; i < m; i++)
        cnt[n[i]-'0']++;
    int idx = 9;
    for(int i = 0; i < m; i++)
    {
        while(cnt[idx] == 0)
            idx--;
        n[i] = '0' + idx;
        cnt[idx]--;
    }

    // precalcolo le potenze di 10
    vector<ll> ppow(m+1, 1);
    for(int i = 1; i <= m; i++)
        ppow[i] = (ppow[i-1]*10) % k;

    // calcolo della congruenza di una stringa
    auto f = [&] (string s) -> ll
    {
        ll res = 0;
        for(int i = 0; i < m; i++)
        {
            res += (n[i] - '0')*ppow[m-i-1];
            res %= k;
        }
        return res;
    };

    // trovo le permutazioni
    map<int,int> first_occ;
    int a = -1, b = -1;
    for(int i = 0; i <= k; i++)
    {
        int c = f(n);
        if(first_occ.count(c))
        {
            b = i;
            a = first_occ[c];
            break;
        }
        first_occ[c] = i;

        if(!prev_permutation(begin(n), end(n)))
            break;

        if(n[0] == '0')
            break;
    }

    if(a == -1 && b == -1)
    {
        cout << -1 << "\n";
    } else
    {
        // recupero le due permutazioni
        cout << n << "\n";
        for(int i = b; i > a; i--)
            next_permutation(begin(n), end(n));
        cout << n << "\n";
    }
}

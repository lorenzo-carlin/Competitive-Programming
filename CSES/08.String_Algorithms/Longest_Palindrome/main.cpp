#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Hash
{
    int n;
    string s;

    int p1 = 29, p2 = 31;
    int m1 = 1e9+7, m2 = 1e9+9;
    
    vector<ll> ppow1, ppow2;
    vector<ll> hash1, hash2;

    Hash() {}
    Hash(string _s) : s(_s), n(_s.size())
    {
        ppow1.resize(n+1, 1);
        ppow2.resize(n+1, 1);
        for(int i = 0; i < n; i++) ppow1[i+1] = (ppow1[i] * p1) % m1;
        for(int i = 0; i < n; i++) ppow2[i+1] = (ppow2[i] * p2) % m2;

        hash1.resize(n+1, 0);
        hash2.resize(n+1, 0);
        for(int i = 0; i < n; i++) hash1[i+1] = (hash1[i] + (s[i] - 'a' + 1) * ppow1[i]) % m1;
        for(int i = 0; i < n; i++) hash2[i+1] = (hash2[i] + (s[i] - 'a' + 1) * ppow2[i]) % m2;
    }

    pair<ll,ll> substrHash(int a, int b)
    {
        ll h1 = (hash1[b+1] - hash1[a] + m1) % m1;
        ll h2 = (hash2[b+1] - hash2[a] + m2) % m2;
        return {h1, h2};
    }

    bool sameHash(int a, int b, int c, int d)
    {
        pair<ll,ll> t1 = substrHash(a, b);
        pair<ll,ll> t2 = substrHash(c, d);

        ll tmp1a = (t1.first * ppow1[c+1]) % m1;
        ll tmp1b = (t1.second * ppow2[c+1]) % m2;
        ll tmp2a = (t2.first * ppow1[a+1]) % m1;
        ll tmp2b = (t2.second * ppow2[a+1]) % m2;

        if(tmp1a == tmp2a && tmp1b == tmp2b) return true;
        return false;
    }
};

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    string s; cin >> s;
    int n = s.size();
    string rev = s;
    reverse(begin(rev), end(rev));
    s += '#';
    s += rev;

    Hash hashing = Hash(s);

    if(n == 1)
    {
        cout << s[0] << "\n";
        return 0;
    }

    // 1^ caso: finestra palindroma di dimensione dispari
    int l1 = 0, r1 = 0;
    int mx1 = 0, idx1 = -1;
    for(; l1 < n && r1 < n; l1++, r1++)
    {
        while(l1 >= 0 && r1 < n && hashing.sameHash(l1, r1, 2*n-r1, 2*n-l1))
        {
            l1--;
            r1++;
        }
        l1++;
        r1--;
        if(r1-l1+1 > mx1)
        {
            mx1 = r1-l1+1;
            idx1 = l1;
        }
    }

    // 2^ caso: finestra palindroma di dimensione pari
    int l2 = 0, r2 = 1;
    int mx2 = 0, idx2 = -1;
    for(; l2 < n && r2 < n; l2++, r2++)
    {
        while(l2 >= 0 && r2 < n && hashing.sameHash(l2, r2, 2*n-r2, 2*n-l2))
        {
            l2--;
            r2++;
        }
        l2++;
        r2--;
        if(r2-l2+1 > mx2)
        {
            mx2 = r2-l2+1;
            idx2 = l2;
        }
    }

    if(mx1 > mx2)
    {
        cout << s.substr(idx1, mx1) << "\n";
    } else
    {
        cout << s.substr(idx2, mx2) << "\n";
    }
}

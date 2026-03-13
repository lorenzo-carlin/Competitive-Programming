#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Hash_1
{
    int n;
    string s;

    int p = 31;
    int m = 1e9+9;
    vector<ll> ppow, hash;

    Hash_1(string _s) : s(_s), n(_s.size())
    {
        ppow.resize(n+1);
        ppow[0] = 1;
        for(int i = 1; i <= n; i++)
            ppow[i] = (ppow[i-1]*p) % m;
        hash.resize(n+1);
        hash[0] = 0;
        for(int i = 1; i <= n; i++)
            hash[i] = hash[i-1] + (((s[i-1]-'a'+1)*ppow[i-1]) % m) % m;
    }
};

struct Hash_2
{
    int n;
    string s;

    int p = 31;
    int m = 1e9+9;
    vector<ll> ppow, hash;

    Hash_2(string _s) : s(_s), n(_s.size())
    {
        ppow.resize(n+1);
        ppow[0] = 1;
        for(int i = 1; i <= n; i++)
            ppow[i] = (ppow[i-1]*p) % m;
        hash.resize(n+1);
        hash[0] = 0;
        for(int i = 1; i <= n; i++)
            hash[i] = hash[i-1] + (((s[i-1]-'a'+1)*ppow[i-1]) % m) % m;
    }

    ll substrHash(int a, int b)
    {
        return ((hash[b+1] - hash[a] + m) % m);
    }

    bool sameHash(int a, int b, int c, int d)
    {
        if(b-a != d-c) return false;
        ll h1 = (substrHash(a, b) * ppow[c]) % m;
        ll h2 = (substrHash(c, d) * ppow[a]) % m;
        return (h1 == h2);
    }
};

struct Hash_3
{
    int n;
    string s;

    int p1 = 29, p2 = 31;
    int m1 = 1e9+7, m2 = 1e9+9;
    vector<ll> ppow1, ppow2, hash1, hash2;

    Hash_3(string _s) : s(_s), n(_s.size())
    {
        ppow1.resize(n+1);
        ppow2.resize(n+1);
        ppow1[0] = ppow2[1] = 1;
        for(int i = 1; i <= n; i++) {
            ppow1[i] = (ppow1[i-1]*p1) % m1;
            ppow2[i] = (ppow2[i-1]*p2) % m2;
        }
        hash1.resize(n+1);
        hash2.resize(n+1);
        hash1[0] = hash2[0] = 0;
        for(int i = 1; i <= n; i++) {
            hash1[i] = hash1[i-1] + (((s[i-1]-'a'+1)*ppow1[i-1]) % m1) % m1;
            hash2[i] = hash2[i-1] + (((s[i-1]-'a'+1)*ppow2[i-1]) % m2) % m2;
        }
    }

    pair<ll,ll> substrHash(int a, int b)
    {
        return {((hash1[b+1] - hash1[a] + m1) % m1), ((hash2[b+1] - hash2[a] + m2) % m2)};
    }

    bool sameHash(int a, int b, int c, int d)
    {
        if(b-a != d-c) return false;
        pair<ll,ll> h1 = {(substrHash(a, b).first * ppow1[c]) % m1, (substrHash(a, b).second * ppow2[c]) % m2};
        pair<ll,ll> h2 = {(substrHash(c, d).first * ppow1[a]) % m1, (substrHash(c, d).second * ppow2[a]) % m2};
        return (h1 == h2);
    }
};


int main()
{
    Hash_3 h = Hash_3("abacababa");
    cout << h.sameHash(0, 2, 6, 8) << "\n";
    cout << h.sameHash(0, 3, 4, 7) << "\n";
    cout << h.sameHash(4, 6, 6, 8) << "\n";
}

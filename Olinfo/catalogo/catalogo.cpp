#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, int> mp;

void aggiungi(ll id) {
    auto itr = mp.find(id);
    if(itr == mp.end())
    {
        mp.insert(make_pair(id, 1));
    } else
    {
        mp[id]++;
    }
}

void togli(long long int id) {
    mp[id]--;
    if(mp[id] == 0)
    {
        mp.erase(id);
    }

}

int conta(long long int id) {
    return mp[id];
}
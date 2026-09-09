#include <bits/stdc++.h>
using namespace std;

set<long long> open;

void inizia() {
    return;
}

void apri(long long p) {
    open.insert(p);
}

void chiudi(long long p) {    
    open.erase(p);
}

long long chiedi(long long p) {
    long long ans = -1;
    auto it = open.lower_bound(p);
    if(open.size() > 0)
    {
        if(it == open.begin())
        {
            ans = *it;
        } else if(it == open.end())
        {
            it--;
            ans = *it;
        } else
        {
            it--;
            long long dif1 = abs(p - *it);
            it++;
            long long dif2 = abs(p - *it);
            if(dif1 > dif2 || dif1 == dif2)
            {
                ans = *it;
            } else if(dif2 > dif1)
            {
                it--;
                ans = *it;
            }
        }
    }
    return ans;
}
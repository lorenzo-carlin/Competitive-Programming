#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    // transizione su tutti gli elementi contenuti nelle mask
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                // transizione
            }
        }
    }

    // transizione su tutti i subset di tutte le mask (ordine decrescente)
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int subm = mask; subm != 0; subm = (subm-1) & mask) {
            // transizione
        }
    }

}

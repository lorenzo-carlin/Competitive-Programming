#include <bits/stdc++.h>
using namespace std;
using ll = long long;

float scosse(int N) {
    ll k = 1;
    ll tot = 0;
    for(int i = 0; i < N; i++, k++)
    {
        tot += k;
    }
    float sc = (float) (tot - N) / 2;
    return sc;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;

    cout << scosse(n) << "\n";
}

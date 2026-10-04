#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int j = n/2; j > 0; j--) {
        if(gcd(n, j) == 1) {
            cout << j << "\n";
            return 0;
        }
    }
}
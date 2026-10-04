#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n), b(n);
    int sumA = 0;
    int total = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sumA += a[i];
        total += b[i];
    }

    for(int i = 0; i < n; i++) {
        int rem = total - sumA + a[i];
        if(rem <= b[i]) {
            cout << i+1 << "\n";
            return 0;
        }
    }

    cout << "impossible\n";
}
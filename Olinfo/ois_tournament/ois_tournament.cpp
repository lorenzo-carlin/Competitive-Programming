#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n), b(n);
    int mx_a = 0, mx_b = 0, mn_a = 1e9, mn_b = 1e9;
    for(int i = 0; i < n; ++i)
    {
        int num; cin >> num;
        a[i] = (num + i);
        mx_a = max(mx_a, a[i]);
        mn_a = min(mn_a, a[i]);
        b[i] = (num - i);
        mx_b = max(mx_b, b[i]);
        mn_b = min(mn_b, b[i]);
    }

    cout << max(mx_a-mn_a, mx_b-mn_b) << "\n";
}
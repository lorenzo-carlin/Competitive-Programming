#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int sum = 2*n;
    for(int i = 0, a; i < n; i++)
    {
        cin >> a;
        sum += a;
    }

    cout << sum << "\n";
}

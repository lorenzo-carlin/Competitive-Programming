#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    if(n == 1) cout << -1 << "\n";
    else
    {
        if(n % 2)
        {
            cout << "111";
            n -= 3;
        }
        while(n > 0)
        {
            cout << "15";
            n -= 2;
        }
        cout << "\n";
    }
}
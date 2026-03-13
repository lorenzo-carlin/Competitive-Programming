#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    while(n--)
    {
        int a, b; cin >> a >> b;
        int sum = a+b, dif = abs(a-b);
        if(sum % 3 == 0 && dif <= min(a, b))
        {
            cout << "YES\n";
        } else
        {
            cout << "NO\n";
        }
    }
}
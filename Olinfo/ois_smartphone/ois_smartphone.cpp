#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    ll mx = 0, sum = 0;
    ll num;
    while(n--)
    {
        cin >> num;
        if(num > mx)
        {
            mx = num;
            sum += num;
        }
    }
    cout << sum << "\n";
    return 0;
}
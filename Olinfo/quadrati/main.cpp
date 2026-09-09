#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a, b; cin >> a >> b;
    ll s1 = sqrt(a), s2 = sqrt(b);
    int sol = s2 - s1;
    if(s1*s1 == a) sol++;
    cout << sol << "\n";
}
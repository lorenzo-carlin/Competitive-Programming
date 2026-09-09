#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct ip
{
    ll a, b, c, d;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char buf;
    ip n1, n2;
    cin >> n1.a >> buf >> n1.b >> buf >> n1.c >> buf >> n1.d;
    cin >> n2.a >> buf >> n2.b >> buf >> n2.c >> buf >> n2.d;

    ll tot = (n2.a-n1.a)*256*256*256 + (n2.b-n1.b)*256*256 + (n2.c-n1.c)*256 + (n2.d-n1.d);
    tot++;
    cout << tot << "\n";
}
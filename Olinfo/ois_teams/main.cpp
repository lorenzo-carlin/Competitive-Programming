#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b; cin >> a >> b;
    cout << min(min(a, b), (a+b)/4) << "\n";
}

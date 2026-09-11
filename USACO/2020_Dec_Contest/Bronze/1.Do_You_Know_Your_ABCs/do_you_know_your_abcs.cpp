#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v(7);
    for(auto &i: v) cin >> i;

    sort(v.begin(), v.end());

    int a = v[0], b = v[1], c = v[6] - (a + b);

    cout << a << " " << b << " " << c << "\n";
}
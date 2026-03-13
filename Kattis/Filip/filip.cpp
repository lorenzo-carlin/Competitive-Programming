#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b; cin >> a >> b;
    string c = to_string(a), d = to_string(b);
    reverse(c.begin(), c.end());
    reverse(d.begin(), d.end());
    a = stoi(c);
    b = stoi(d);
    cout << max(a,b) << "\n";
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string num; cin >> num;
    int n1 = stoi(num);

    reverse(num.begin(), num.end());
    int n2 = stoi(num);

    cout << n1+n2 << "\n";
}
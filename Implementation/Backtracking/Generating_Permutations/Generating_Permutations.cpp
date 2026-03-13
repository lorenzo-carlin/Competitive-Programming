#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> v(n);
    for(auto &i: v) cin >> i;

    sort(v.begin(), v.end());

    do
    {
        for(auto el: v) cout << el << " ";
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
}
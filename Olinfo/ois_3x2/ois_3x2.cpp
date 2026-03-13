#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    int tot = 0;
    for(auto &i: v) { cin >> i; tot += i;}

    sort(v.rbegin(), v.rend());
    for(int i = 0; i < n; ++i)
    {
        if(i % 3 == 2)
        {
            tot -= v[i];
        }
    }

    cout << tot << "\n";
}
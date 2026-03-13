#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, k; cin >> m >> k;
    string n; cin >> n;

    sort(rbegin(n), rend(n));
    map<int,vector<string>> v;

    vector<int> ppow(k, 1);
    for(int i = 1; i < k; i++)
        ppow[i] = (ppow[i-1]*10) % k;

    auto calc = [&] (string s) -> ll
    {
        int res = 0;
        for(int i = 0; i < m; i++)
            res = ((res + (((s[i] - '0')*ppow[m-i-1]) % k)) % k);
        return res;
    };

    int cnt = 0;
    do
    {
        if(n[0] == '0') break;
        int c = calc(n);
        v[c].push_back(n);
        cnt++;
    } while(cnt <= k && prev_permutation(begin(n), end(n)));

    for(auto el: v)
    {
        if(el.second.size() > 1)
        {
            cout << el.second[0] << "\n";
            cout << el.second[1] << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
}

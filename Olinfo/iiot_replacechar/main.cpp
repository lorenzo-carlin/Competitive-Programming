#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        v[i] = s[i]-'a';
    }

    vector<int> l(n+1, INF);
    vector<int> idx(n+1, -1);
    vector<int> p(n+1, -1);
    l[0] = -INF;
    for(int i = 0; i < n; ++i)
    {
        int t = upper_bound(begin(l), end(l), v[i]) - begin(l);
        if(l[t-1] <= v[i] && v[i] < l[t])
        {
            l[t] = v[i];
            idx[t] = i;
            p[i] = idx[t-1];
        }
    }

    int sol = 0;
    for(int i = 1; i < n+1; ++i)
    {
        if(l[i] != INF)
        {
            sol = i;
        }
    }

    int ans = n-sol;
    // for(auto el: l) cout << el << " ";
    // cout << "\n";
    // for(auto el: idx) cout << el << " ";
    // cout << "\n";
    // for(auto el: p) cout << el << " ";
    // cout << "\n";

    vector<int> lis;
    int tmp = idx[sol];
    lis.push_back(tmp);
    while(p[tmp] != -1)
    {
        tmp = p[tmp];
        lis.push_back(tmp);
    }
    reverse(begin(lis), end(lis));
    // for(auto el: lis) cout << el << " ";
    // cout << "\n";

    cout << ans << "\n";
    int cnt = 0;
    char last = 'a';
    for(int i = 0; i < n; ++i)
    {
        if(cnt < sol && i == lis[cnt])
        {
            cnt++;
            last = s[i];
            continue;
        } else
        {
            cout << i << " " << last << "\n";
        }
    }
}
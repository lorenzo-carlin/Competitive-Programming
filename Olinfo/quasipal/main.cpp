#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> v;
int n, m;

bool possible()
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m/2; ++j)
        {
            if(v[j][i] != v[m-1-j][i] && v[j][i] != '0' && v[m-1-j][i] != '0') return false;
        }
    }
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    v.resize(m);
    for(int i = 0; i < m; ++i) cin >> v[i];
    
    sort(v.begin(), v.end());
    do
    {
        if(possible())
        {
            for(auto el: v) cout << el << "\n";
            break;
        }
    } while (next_permutation(v.begin(), v.end()));
}
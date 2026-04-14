#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<array<int,4>> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i][1] >> v[i][2] >> v[i][0];
        v[i][3] = i;
    }

    sort(begin(v), end(v));
    vector<int> mnD(n, 1e9);

    auto dist = [&] (int x, int y) -> int
    {
        return (v[x][1] - v[y][1])*(v[x][1] - v[y][1]) + (v[x][2] - v[y][2])*(v[x][2] - v[y][2]);
    };

    vector<int> ans(n);

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            mnD[i] = min(mnD[i], dist(i, j));
        }

        ans[v[i][3]] = min(v[i][0], int(sqrt(mnD[i])));
    }

    for(int el: ans) cout << el << "\n";
}

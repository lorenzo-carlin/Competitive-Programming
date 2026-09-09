#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    int win; cin >> win;
    for(int i = 1; i < n; ++i)
    {
        int tmp; cin >> tmp;
    }

    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        if(b == win) win = a;
    }

    cout << win << "\n";
}
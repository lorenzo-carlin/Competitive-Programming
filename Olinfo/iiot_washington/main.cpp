#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int,int> NE(char x, int y)
{
    return {(x-'A'), y};
}

pair<int,int> NW(char x, int y)
{
    return {-(x-'A'), y};
}

pair<int,int> SW(char x, int y)
{
    return {-(x-'A'), (y == 0) ? (0) : -(26-y)};
}

pair<int,int> SE(char x, int y)
{
    return {(x-'A'), (y == 0) ? (0) : -(26-y)};
}

void solve()
{
    string c1, c2;
    char x1, x2;
    int y1, y2;
    cin >> c1 >> x1 >> y1 >> c2 >> x2 >> y2;

    pair<int,int> a, b;
    if(c1 == "NE") a = NE(x1, y1);
    else if(c1 == "NW") a = NW(x1, y1);
    else if(c1 == "SE") a = SE(x1, y1);
    else if(c1 == "SW") a = SW(x1, y1);
    if(c2 == "NE") b = NE(x2, y2);
    else if(c2 == "NW") b = NW(x2, y2);
    else if(c2 == "SE") b = SE(x2, y2);
    else if(c2 == "SW") b = SW(x2, y2);

    // cout << a.first << " " << a.second << " " << b.first << " " << b.second << "\n";

    int dist = abs(a.first-b.first) + abs(a.second-b.second);

    cout << dist << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    while(n--) solve();
}
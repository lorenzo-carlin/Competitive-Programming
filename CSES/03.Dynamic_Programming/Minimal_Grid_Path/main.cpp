#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<vector<char>> mat(n, vector<char> (n));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
        }
    }

    vector<vector<string>> memo(n, vector<string> (n, "0"));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            memo[i][j] = "0";
        }
    }

    auto solve = [&] (auto solve, int x, int y) -> string
    {
        if(memo[x][y] != "0") return memo[x][y];

        string s;
        if(x == n-1 && y == n-1) s = "";
        else if(x == n-1) s = solve(solve, x, y+1);
        else if(y == n-1) s = solve(solve, x+1, y);
        else s = min(solve(solve, x+1, y), solve(solve, x, y+1));

        s = mat[x][y] + s;
        return memo[x][y] = s;
    };

    cout << solve(solve, 0, 0) << "\n";
}

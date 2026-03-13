#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<vector<char>> mat(n, vector<char> (m));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> mat[i][j];
        }
    }
    cout << "free\n";
}

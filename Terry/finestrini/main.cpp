#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

int dp(int pos, string s, vector<int> &left, vector<int> &right, vector<vector<int>> &mat)
{
    // casi base
    if(pos == n)
        return 0;
    if(s == "11")
        return dp(pos+1, "10", left, right, mat) + left[pos];
    if(s == "00")
        return dp(pos+1, "01", left, right, mat) + right[pos];
    
    //cout << mat[0][0] << endl;
    if((s == "00" || s == "0") && mat[pos][0] != -1)
        return mat[pos][0];
    if((s == "01" || s == "1") && mat[pos][1] != -1)
        return mat[pos][1];
    if(s == "10" && mat[pos][2] != -1)
        return mat[pos][2];
    if(s == "11" && mat[pos][3] != -1)
        return mat[pos][3];
    
    // caso generale
    int mn = INT_MAX;
    if(s.size() == 2)
    {
        s.erase(s.begin());
    }
    // apro a sinistra
    mn = min(mn, dp(pos+1, s+"0", left, right, mat) + left[pos]);
    // apro a destra
    mn = min(mn, dp(pos+1, s+"1", left, right, mat) + right[pos]);
    if(s == "00" || s == "0")
        mat[pos][0] = mn;
    if(s == "01" || s == "1")
        mat[pos][1] = mn;
    if(s == "10")
        mat[pos][2] = mn;
    if(s == "11")
        mat[pos][3] = mn;
    return mn;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; cin >> t;
    for(int p = 1; p <= t; ++p)
    {
        cin >> n;
        vector<int> left;
        vector<int> right;
        vector<vector<int>> mat(n);
        for(int i = 0; i < n; ++i)
        {
            int a, b; cin >> a >> b;
            left.push_back(a);
            right.push_back(b);
            for(int j = 0; j < 4; ++j)
            {
                mat[i].push_back(-1);
            }
        }
        int ans = dp(0, "", left, right, mat);
        cout << "Case #" << p << ": " << ans << endl;
    }
}
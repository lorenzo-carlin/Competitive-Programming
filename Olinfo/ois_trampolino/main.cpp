#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for(auto &el: v) cin >> el;

    int mx = v[0], mx_ind = 0;
    int sol = 1;
    while(mx_ind + v[mx_ind] < n)
    {
        int tmp_mx = -1, tmp_mx_ind = -1;
        for(int i = 1; i <= v[mx_ind]; ++i)
        {
            if(v[mx_ind+i]+i > tmp_mx)
            {
                tmp_mx = v[mx_ind+i]+i;
                tmp_mx_ind = mx_ind+i;
            }
        }
        mx = tmp_mx, mx_ind = tmp_mx_ind;
        sol++;
    }

    cout << sol << "\n";
}
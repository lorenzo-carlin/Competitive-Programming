#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> das(n), as(m);
    for (int &tmp : das) cin >> tmp;
    for (int &tmp : as) cin >> tmp;
    sort(das.begin(), das.end());
    sort(as.begin(), as.end());
    int ris = 0;
    for(int i = 0, j = 0; i < n && j < m; i++)
    {
        while(j < m && as[j] <= das[i] && (das[i] - as[j]) > k)
        {
            j++;
        }
        if(j < m && abs(das[i] - as[j]) <= k)
        {
            ris++;
            j++;
        }
    }
    cout << ris;
    return 0;
}
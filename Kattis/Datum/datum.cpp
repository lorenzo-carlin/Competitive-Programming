#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string week[7] = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};
    int d, m; cin >> d >> m;
    int d_tot = 0;
    for(int i = 1; i < m; ++i)
    {
        d_tot += days[i];
    }
    d_tot += d;
    cout << week[d_tot%7] << "\n";
}
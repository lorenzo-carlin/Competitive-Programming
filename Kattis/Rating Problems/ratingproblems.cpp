#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int sum = 0;
    for(int i = 0; i < m; ++i)
    {
        int num; cin >> num;
        sum += num;
    }
    float mn_overall = (float) (sum + ((n-m)*(-3))) / n;
    float mx_overall = (float) (sum + ((n-m)*3)) / n;

    cout << mn_overall << " " << mx_overall << "\n";
}
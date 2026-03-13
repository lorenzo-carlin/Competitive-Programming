#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int mx = 0;
long long lim;

void cabala(char last, long long num, int n, int m)
{
    if(num > lim) return;

    int ans = num % m;
    if(ans > mx)
    {
        mx = ans;
    }

    long long next = num * 10;
    if(last == '3')
    {
        cabala('6', next+6, n, m);
        cabala('9', next+9, n, m);
    } else if(last == '6')
    {
        cabala('3', next+3, n, m);
        cabala('9', next+9, n, m);
    } else if(last == '9')
    {
        cabala('3', next+3, n, m);
        cabala('6', next+6, n, m);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while(t--)
    {
        mx = 0;
        int n, m; cin >> n >> m;
        lim = pow(10, n);
        cabala('3', 3, n, m);
        cabala('6', 6, n, m);
        cabala('9', 9, n, m);
        cout << mx << " ";
    }
}
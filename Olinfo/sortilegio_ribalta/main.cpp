#include <bits/stdc++.h>
using namespace std;

int ribalta(int n, string s)
{
    int mx = 0, tot = 0, uno = 0;
    for(int i = 0; i < n; i++)
        tot += (s[i] == '1');

    mx = tot;
    for(int i = 0; i < n; i++)
    {
        uno += (s[i] == '1');
        tot -= (s[i] == '1');

        mx = max(mx, i+1-uno+tot);
    }

    return mx;
}

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N; cin >> N;

    string S; cin >> S;

    cout << ribalta(N, S) << endl;
}

#endif

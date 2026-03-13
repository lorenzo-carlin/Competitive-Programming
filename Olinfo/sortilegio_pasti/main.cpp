#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dividi(int n, vector<int> v)
{
    int t = 0;
    for(int el: v) t += el;

    vector<bool> pos(t+1, false);
    pos[0] = true;
    int mn = 1e9;
    for(int i = 0; i < n; i++)
    {
        for(int j = t; j >= 0; j--)
        {
            if(pos[j] && j+v[i] <= t)
            {
                pos[j+v[i]] = true;
                int a = j+v[i];
                int b = t-a;
                mn = min(mn, abs(b-a));
            }
        }
    }

    return mn;
}

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;

    vector<int> V(N);
    for(auto &x: V) cin >> x;

    cout << dividi(N, V) << endl;
}

#endif

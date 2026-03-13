#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, c, w; cin >> n >> c >> w;
    vector<int> t(n);
    for(int &i: t) cin >> i;
    sort(rbegin(t), rend(t));

    int sz = (n+c-1)/c;
    vector<int> T(sz);
    for(int i = 0; i < sz; i++)
        T[i] = t[c*i];



    int lavo = 0, inizio = 0, fine = 0;
    for(int i = 0; i < sz; i++)
    {
        lavo += w;
        inizio = max(fine, lavo);
        fine = inizio + T[i];
    }

    cout << fine << "\n";
}

#include <bits/stdc++.h>
using namespace std;

void Colora(int N, int Q, vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &murale)
{
    for(int i = 0; i < N; ++i) murale[i] = 0;

    set<int> s;
    auto it = s.begin();
    for(int i = 0; i <= N; ++i) s.insert(it, i);
    for(int i = Q-1; i >= 0; --i)
    {
        it = s.lower_bound(A[i]);
        while((*it) <= B[i])
        {
            murale[*it] = C[i];
            it = s.erase(it);
        }
    }
}

int main()
{
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n), c(n), murale(n, 0);
    for(int i = 0; i < q; ++i) cin >> a[i] >> b[i] >> c[i];
    Colora(n, q, a, b, c, murale);
    for(auto el: murale) cout << el << " ";
}
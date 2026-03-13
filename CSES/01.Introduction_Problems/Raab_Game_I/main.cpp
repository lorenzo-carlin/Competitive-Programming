#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, a, b; cin >> n >> a >> b;

    if(a+b > n)
    {
        cout << "NO\n";
        return;
    }

    int par = n - (a + b);
    vector<int> A, B;
    for(int i = n; i > (a+b); i--)
    {
        A.push_back(i);
        B.push_back(i);
    }
    int l = a+b;
    int r = a;
    for(int i = 0; i < a+b; i++)
    {
        if(r == 0) r = n-par;
        A.push_back(l);
        B.push_back(r);
        l--; r--;
    }

    // verifica
    int pA = 0, pB = 0;
    for(int i = 0; i < n; ++i)
    {
        if(A[i] > B[i]) pA++;
        else if(A[i] < B[i]) pB++;
    }

    if(pA != a || pB != b)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for(auto el: A) cout << el << " ";
    cout << "\n";
    for(auto el: B) cout << el << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}

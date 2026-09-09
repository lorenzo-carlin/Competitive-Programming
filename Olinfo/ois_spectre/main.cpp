#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> targets;
    int n, sol; cin >> n;
    for(int i = 0; i < n; ++i)
    {
        string t, ug, op1, op, op2; cin >> t >> ug >> op1 >> op >> op2;
        targets.insert(t);
        if(targets.count(op1) == 0 && targets.count(op2) == 0) sol++;
    }
    cout << sol << "\n";
}
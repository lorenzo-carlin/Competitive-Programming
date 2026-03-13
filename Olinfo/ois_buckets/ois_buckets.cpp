#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    set<int> s;
    for(int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        s.insert(a);
    }

    if(s.size() == n)
    {
        cout << "Ok\n";
    } else
    {
        cout << "Impossible\n";
    }
}
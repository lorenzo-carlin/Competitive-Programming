#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e; cin >> n >> e;
    vector<int> prec(n, -1);
    map<int,int> pnt;

    for(int i = 0; i < e; ++i)
    {
        int a, b; cin >> a >> b;
        if(a == b)
        {
            pnt[prec[a]]--;
        } else
        {
            pnt[a]++;
            prec[b] = a;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        cout << pnt[i] << " ";
    }
    cout << "\n";
}
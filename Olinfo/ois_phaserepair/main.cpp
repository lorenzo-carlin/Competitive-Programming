#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int> res(m, 0);
    for(int i = 0; i < n; i++)
    {
        int c; cin >> c;
        res[c]++;
    }

    int last = 0, st = 0, fn = m-1, mx = -1, fst = -1;
    for(int i = 0; i < m; i++)
    {
        if(res[i] && (i-last-1) > mx)
        {
            mx = (i-last-1);
            fn = last;
            st = i;
        }

        if(res[i] && fst == -1) fst = i;

        if(res[i]) last = i;
    }

    if(((fst - last - 1 + m) % m) > mx)
    {
        mx = ((fst-last-1+m)%m);
        st = fst;
        fn = last;
    }

    if(fn == st)
    {
        cout << 0 << "\n";
        return 0;
    }

    cout << (fn-st+m)%m << "\n";
    if(fn > st)
    {
        for(int i = st; i < fn; i++)
            cout << i << " ";
        cout << "\n";
    } else
    {
        for(int i = st; i < m; i++)
            cout << i << " ";
        for(int i = 0; i < fn; i++)
            cout << i << " ";
        cout << "\n";
    }
}

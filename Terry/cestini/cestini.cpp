#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        //input
        int n, m, q; cin >> n >> m >> q;
        string s; cin >> s;

        cout << "Case #" << i << ": ";

        //creazione cestini e assegnazione stringa s al primo cestino
        vector<string> v(m);
        v[0] = s;

        //operazioni dugli elementi
        for(int i = 0; i < q; ++i)
        {
            char c;
            int a, b;
            cin >> c >> a >> b;
            if(c == 's')                //scambio di due elementi
            {
                int cnt = v[a].size();
                char tmp = v[a][cnt-1];
                v[a].erase(cnt-1);
                v[b] += tmp;
            } else if(c == 'c')         //controllo di un elemento
            {
                cout << v[a][b];
            }
        }
        cout << endl;
    }
}
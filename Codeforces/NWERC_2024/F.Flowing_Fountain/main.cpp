#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, q; cin >> n >> q;
    vector<int> v(n), c(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        c[i] = v[i];
    }

    vector<int> nxt(n, -1);
    stack<int> s;
    s.push(n-1);
    for(int i = n-2; i >= 0; i--)
    {
        while(!s.empty() && v[s.top()] <= v[i])
            s.pop();
        if(!s.empty()) nxt[i] = s.top();
        s.push(i);
    }

    // simulazione
    while(q--)
    {
        char car; cin >> car;
        if(car == '+')
        {
            int l, x; cin >> l >> x; l--;
            int idx = l, rem = x;
            stack<int> path; // percorso che faccio, per aggiornare i nxt
            
            while(idx != -1 && rem > 0)
            {
                path.push(idx);

                // ci sta in questo
                if(rem < c[idx])
                {
                    c[idx] -= rem;
                    rem = 0;
                    path.pop();
                } else // straborda
                {
                    rem -= c[idx];
                    c[idx] = 0;
                    idx = nxt[idx];
                }
            }
            // aggiorno i nxt
            int last = idx;
            while(!path.empty())
            {
                nxt[path.top()] = last;
                path.pop();
            }
        } else
        {
            int l; cin >> l; l--;
            cout << (v[l]-c[l]) << "\n";
        }
    }
}

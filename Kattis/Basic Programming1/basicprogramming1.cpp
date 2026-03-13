#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, t; cin >> n >> t;
    vector<ll> v(n);

    // input dell'array
    for(auto &i:v) cin >> i;

    switch(t)
    {
        case 1:
        {
            cout << "7" << "\n";
            break;
        }

        case 2:
        {
            if(v[0] > v[1])
            {
                cout << "Bigger" << "\n";
            }
            if(v[0] == v[1])
            {
                cout << "Equal" << "\n";
            }
            if(v[0] < v[1])
            {
                cout << "Smaller" << "\n";
            }
            break;
        }
        
        case 3:
        {
            vector<ll> p;
            p.push_back(v[0]);
            p.push_back(v[1]);
            p.push_back(v[2]);
            sort(p.begin(), p.end());
            cout << p[1] << "\n";
            break;
        }

        case 4:
        {
            ll sum = 0;
            for(int i = 0; i < n; ++i)
            {
                sum += v[i];
            }
            cout << sum << "\n";
            break;
        }

        case 5:
        {
            ll sum_ev = 0;
            for(int i = 0; i < n; ++i)
            {
                if(v[i]%2==0)
                    sum_ev+=v[i];
            }
            cout << sum_ev << "\n";
            break;
        }

        case 6:
        {
            string a;
            for(int i = 0; i < n; ++i)
            {
                v[i] = v[i]%26;
                char c = v[i] + 'a';
                a += c;
            }
            cout << a << "\n";
            break;
        }

        case 7:
        {
            ll ind = 0, q = 0;
            while(ind <= n)
            {
                if(q >= n)
                {
                    cout << "Out\n";
                    break;
                }
                if(q == n-1)
                {
                    cout << "Done\n";
                    break;
                }
                q = v[q];
                ind++;
            }
            if(ind == n+1)
            {
                cout << "Cyclic\n";    
            }
            break;
        }

    }
}
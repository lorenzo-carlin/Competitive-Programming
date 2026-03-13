#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<string> v;
    int min_err = 1001;
    int min_ind = -1;

    int n, m; cin >> n >> m;

    // soluzione corretta
    for(int i = 1; i <= m; ++i)
    {
        if(i % 3 == 0 && i % 5 == 0)
        {
            v.push_back("fizzbuzz");
        } else if(i % 3 == 0)
        {
            v.push_back("fizz");
        } else if(i % 5 == 0)
        {
            v.push_back("buzz");
        } else
        {
            v.push_back(to_string(i));
        }
    }

    // calcolo errori candidati
    for(int i = 0; i < n; ++i)
    {
        int curr = 0;
        for(int j = 0; j < m; ++j)
        {
            string a; cin >> a;
            if(a != v[j])
            {
                curr++;
            }
        }
        if(curr < min_err)
        {
            min_err = curr;
            min_ind = i+1;
        }
    }

    cout << min_ind << "\n";
}
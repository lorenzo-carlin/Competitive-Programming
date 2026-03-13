#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for(auto &i:v) cin >> i;
    queue<int> q;
    int pari1, dispari1, pari2, dispari2;
    for(int i = 0; i < v.size(); ++i)
    {
        // numeri prima
        pari1 = 0;
        dispari1 = 0;
        for(int j = i-1; j >= 0; --j)
        {
            if(v[j]%2==0)
            {
                pari1++;
            } else
            {
                dispari1++;
            }
        }

        // numeri dopo
        pari2 = 0;
        dispari2 = 0;
        for(int j = i+1; j < v.size(); ++j)
        {
            if(v[j]%2==0)
            {
                pari2++;
            } else
            {
                dispari2++;
            }
        }

        //controllo
        if(pari1==dispari1 && pari2==dispari2)
        {
            q.push(v[i]);
        }
    }

    cout << q.size() << "\n";
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}
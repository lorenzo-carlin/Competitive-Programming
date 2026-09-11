#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int cas = 1; cas <= t; ++cas)
    {
        int a, b; cin >> a >> b;
        int tmp = 2*(a+b);
        int s = sqrt(tmp);
        vector<char> sol(s);

        if(s*(s+1) != tmp)
        {
            cout << "Case #" << cas << ": IMPOSSIBILE\n";
        } else
        {
            for(int i = s; i > 0; i--)
            {
                if(a > b)
                {
                    sol[i-1] = '1';
                    a -= i;
                } else
                {
                    sol[i-1] = '2';
                    b -= i;
                }
            }

            cout << "Case #" << cas << ": ";
            for(auto el: sol) cout << el;
            cout << "\n";
        }
    }
}
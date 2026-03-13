#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c, a, b;
    cin >> c;
    string op;
    while(c != 0)
    {
        vector<int> v(32, -1);
        for(int i = 0; i < c; ++i)
        {
            cin >> op;
            if(op == "SET")
            {
                cin >> a;
                v[a] = 1;
            }
            if(op == "CLEAR")
            {
                cin >> a;
                v[a] = 0;
            }
            if(op == "OR")
            {
                cin >> a >> b;
                if(v[a] == -1 || v[b] == -1) {v[a] = -1; v[b] = -1;}
                else v[a] = (v[a] | v[b]);
            }
            if(op == "AND")
            {
                cin >> a >> b;
                if(v[a] == -1 || v[b] == -1) {v[a] = -1; v[b] = -1;}
                else v[a] = v[a] & v[b];
            }
        }

        reverse(v.begin(), v.end());
        for(auto el: v)
        {
            if(el == -1) cout << "?";
            else cout << el;
        }
        cout << "\n";

        cin >> c;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    vector<int> v(3, 0);
    v[0] = 1;
    for(auto el:s)
    {
        if(el == 'A')
        {
            swap(v[0], v[1]);
        } else if(el == 'B')
        {
            swap(v[1], v[2]);
        } else if(el == 'C')
        {
            swap(v[0], v[2]);
        }
    }
    if(v[0] == 1) cout << 1 << "\n";
    if(v[1] == 1) cout << 2 << "\n";
    if(v[2] == 1) cout << 3 << "\n";
}
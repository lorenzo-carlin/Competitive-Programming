#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--)
    {
        int A, C, r, g, b; cin >> A >> C >> r >> g >> b;
        r++;
        int pr = A*(r*r+g*g+b*b)+C*min(r,min(g,b));
        r--;
        g++;
        int pg = A*(r*r+g*g+b*b)+C*min(r,min(g,b));
        g--;
        b++;
        int pb = A*(r*r+g*g+b*b)+C*min(r,min(g,b));
        b--;
        if(pr >= pg && pr >= pb)
        {
            cout << "RED\n";
        } else if(pg >= pr && pg >= pb)
        {
            cout << "GREEN\n";
        } else
        {
            cout << "BLUE\n";
        }
    }
}
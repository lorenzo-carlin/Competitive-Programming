#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;

    int z = 1, y = 2, x = 3;

    while(n--)
    {
        char move; cin >> move;
        int tmp;
        switch (move)
        {
            case 'X':
                tmp = 7-y;
                y = z;
                z = tmp;
                break;
            
            case 'Y':
                tmp = 7-z;
                z = x;
                x = tmp;
                break;
            
            case 'Z':
                tmp = 7-x;
                x = y;
                y = tmp;
                break;
            
            case 'T':
                cout << z << " ";
                break;
            
            case 'F':
                cout << y << " ";
                break;
            
            default:
                cout << x << " ";
                break;
        }
    }
}
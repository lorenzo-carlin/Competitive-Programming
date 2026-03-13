#include <iostream>
using namespace std;

int main()
{
    int a1, b1; cin >> a1 >> b1;
    int a2, b2; cin >> a2 >> b2;
    int a3, b3; cin >> a3 >> b3;
    int a4, b4;

    // a4
    if(a1 == a2)
    {
        a4 = a3;
    } else if(a1 == a3)
    {
        a4 = a2;
    } else if(a2 == a3)
    {
        a4 = a1;
    }

    // b4
    if(b1 == b2)
    {
        b4 = b3;
    } else if(b1 == b3)
    {
        b4 = b2;
    } else if(b2 = b3)
    {
        b4 = b1;
    }

    cout << a4 << " " << b4 << "\n";
}
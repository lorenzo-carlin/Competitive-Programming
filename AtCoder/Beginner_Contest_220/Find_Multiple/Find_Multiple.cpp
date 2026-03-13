#include <iostream>
using namespace std;

int main()
{
    int a, b, c; cin >> a >> b >> c;
    int t = c;
    while(t <= b)
    {
        if(t >= a)
        {
            cout << t;
            return 0;
        } else
        {
            t += c;
        }
    }
    cout << -1;
}
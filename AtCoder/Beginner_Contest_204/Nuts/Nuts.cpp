#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int c = 0;
    for(int i = 0; i < n; ++i)
    {
        int t; cin >> t;
        if(t > 10)
            c += (t-10);
    }
    cout << c;
}
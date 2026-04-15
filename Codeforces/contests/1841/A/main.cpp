#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        if(n > 4) cout << "Alice\n";
        if(n <= 4) cout << "Bob\n";
    }
}

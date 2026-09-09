#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int count = 0;
    int Ham = 100000;
    for(int i = 0; i < n; ++i)
    {
        int t; cin >> t;
        count += t;
        if(t < Ham)
            Ham = t;
    }
    int Ver = 100000;
    for(int i = 0; i < n; ++i)
    {
        int t; cin >> t;
        count -= t;
        if(t < Ver)
            Ver = t;
    }
    if(count > 0)
    {
        cout << "Verstappen\n";
    } else
    {
        cout << "Hamilton\n";
    }
    if(Ham < Ver)
    {
        cout << "Hamilton";
    } else
    {
        cout << "Verstappen";
    }
}
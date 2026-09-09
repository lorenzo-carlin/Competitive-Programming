#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int st, fn; cin >> st >> fn;
    for(int i = 0; i < n-1; ++i)
    {
        int a, b; cin >> a >> b;
        if(b < st || a > fn)
        {
            cout << "NO";
            return 0;
        } else
        {
            st = a;
            fn = b;
        }
    }
    cout << "YES";
    return 0;
}
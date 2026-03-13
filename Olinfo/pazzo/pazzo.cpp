#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    int first = 0;
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        if(a == first)
        {
            first = b;
        } else if(b == first)
        {
            first = a;
        }
    }
    cout << first << "\n";
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int tot = 0, cnt = 0;
    for(int i = 0, a; i < n; i++)
    {
        cin >> a;
        tot += a;
        if(a) cnt++;
    }
    tot -= cnt;

    cout << tot << "\n";
}

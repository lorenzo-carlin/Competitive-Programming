#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int edgl = 1;

    for(int i = 0; i < n; ++i)
    {
        edgl *= 2;
    }

    edgl++;

    cout << edgl*edgl << "\n";
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s3 = "2 7\n6 2\n4 6\n7 4\n";
    string s4 = "4 9\n6 4\n2 6\n5 2\n9 5\n";
    string s5 = "5 11\n2 5\n9 2\n6 9\n3 6\n11 3\n";

    int n; cin >> n;

    if(n == 3) cout << 4 << " " << 3 << "\n" << s3;
    else if(n == 4) cout << 5 << " " << 4 << "\n" << s4;
    else if(n == 5) cout << 6 << " " << 5 << "\n" << s5;
    else
    {
        int tot = 7 + 2*(n-5);
        cout << tot << " " << n << "\n";

        int ind = n, last = 2*n+1;
        while(ind > 5)
        {
            cout << ind << " " << last << "\n";
            last = ind;
            cout << 2*ind-1 << " " << last << "\n";
            last = 2*ind-1;
            ind--;
        }

        cout << s5;
        cout << 2*n+1 << " " << last << "\n";
    }
}
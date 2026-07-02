#include <bits/stdc++.h>
using namespace std;
using ld = long double;

constexpr ld PI = 3.141592653589793238462643383279502884L;

void solve()
{
    ld m, t; cin >> m >> t;

    auto area = [&] (ld k) -> ld
    {
        ld l = (t-m*k)/k;
        return (k * l * l) / (4.0L * tanl(PI/k));
    };

    auto ternary_search = [&] (int l, int r) -> ld
    {
        while (r - l > 3) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            (area(ld(m1)) < area(ld(m2))) ? (l = m1) : (r = m2);
        }

        int res = l;
        for(int i = l+1; i <= r; i++)
        {
            if(area(i) > area(res))
                res = i;
        }

        return area(res);
    };

    int st = 3, fn = t/m;

    if(fn < st) cout << 0 << "\n";
    else cout << fixed << setprecision(15) << ternary_search(st, fn) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c; cin >> c;
    while(c--) solve();
}

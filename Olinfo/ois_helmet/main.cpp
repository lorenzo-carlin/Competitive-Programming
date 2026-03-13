#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    vector<int> points(n);
    iota(begin(points), end(points), 0);

    srand(time(NULL));

    auto dist = [&] (int a, int b) -> ll
    {
        ll dx = x[a] - x[b];
        ll dy = y[a] - y[b];
        return dx*dx + dy*dy;
    };

    int k = 18;

    auto random = [&] (vector<int> &p) -> pair<ll,ll>
    {
        int dim = p.size();
        int cnt = 0;
        int bestA = -1, bestB = -1, best = 1e9;
        while(cnt < k)
        {
            int a = rand() % dim;
            int b = a;
            while(b == a)
            {
                b = rand() % dim;
            }

            a = points[a];
            b = points[b];

            int vicA = 0, vicB = 0;
            for(int x: p)
            {
                if(dist(a, x) <= dist(b, x))
                {
                    vicA++;
                } else
                {
                    vicB++;
                }
            }
            if(abs(vicA-vicB) < best)
            {
                best = abs(vicA-vicB);
                bestA = a;
                bestB = b;
            }
            
            cnt++;
        }

        return {bestA, bestB};
    };

    vector<int> newPoints;
    while(points.size() > 1)
    {
        newPoints.clear();

        auto [c1, c2] = random(points);
        cout << "? " << c1 << " " << c2 << "\n";
        cout.flush();

        int res; cin >> res;
        for(int x: points)
        {
            if(dist(c1, x) <= dist(c2, x))
            {
                if(res == 0)
                {
                    newPoints.push_back(x);
                }
            } else
            {
                if(res == 1)
                {
                    newPoints.push_back(x);
                }
            }
        }

        swap(points, newPoints);
    }

    cout << "! " << points.front() << "\n";
    cout.flush();
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    int n; cin >> n;
    string s; cin >> s;
    vector<array<double,2>> boys, girls;
    double a, b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if(s[i] == 'B') boys.push_back({a, b});
        else girls.push_back({a, b});
    }

    double epsilon = 1e-9;

    auto cmp = [&] (array<double,2> a, array<double,2> b) -> bool
    {
        if((a[1] - b[1]) > epsilon) return a[1] < b[1];
        else return a[0] < b[0];
    };

    auto order = [&] (vector<array<double,2>> v) -> vector<array<double,2>>
    {
        vector<array<double,2>> xpos, xneg;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i][0] >= 0.0) xpos.push_back(v[i]);
            else xneg.push_back(v[i]);
        }
        sort(begin(xpos), end(xpos), cmp);
        sort(begin(xneg), end(xneg), cmp);
        reverse(begin(xneg), end(xneg));

        for(auto el: xneg) xpos.push_back(el);
        return xpos;
    };

    vector<array<double,2>> v1 = order(boys);
    vector<array<double,2>> v2 = order(girls);

    auto calculate = [&] (vector<array<double,2>> v) -> double
    {
        double ans = 0.0;
        int sz = v.size();
        for(int i = 0; i < sz/2; i++)
        {
            ans += sqrt((v[i][0]-v[sz/2+i][0])*(v[i][0]-v[sz/2+i][0]) + (v[i][1]-v[sz/2+i][1])*(v[i][1]-v[sz/2+i][1]));
        }
        return ans;
    };

    double sol = 0.0;

    sol += calculate(boys);
    sol += calculate(girls);

    cout<<fixed<<setprecision(16);
    cout << sol << "\n";
}

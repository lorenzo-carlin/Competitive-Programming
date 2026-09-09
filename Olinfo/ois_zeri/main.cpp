#include <bits/stdc++.h>
using namespace std;

int f(int num, int base)
{
    int sol = 0;
    while(num%base==0)
    {
        sol++;
        num/=base;
    }
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s; cin >> s;
    vector<int> v;
    int tmp = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == 'x')
        {
            v.push_back(tmp);
            tmp = 0;
        } else
        {
            tmp *= 10;
            tmp += (s[i]-'0');
        }
    }
    v.push_back(tmp);

    int two = 0, five = 0, ten = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        while(v[i]%10==0)
        {
            ten++;
            v[i]/=10;
        }
        two += f(v[i], 2);
        five += f(v[i], 5);
    }
    int sol = ten + min(two, five);
    cout << sol << "\n";
}
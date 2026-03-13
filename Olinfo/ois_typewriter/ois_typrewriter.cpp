#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, c; cin >> a >> b >> c;
    a += 'A'; b += 'B'; c += 'C';
    string aa, bb, cc;

    for(int i = 0; i < a.size()-1; ++i)
    {
        if(a[i] != a[i+1]) aa += a[i];
    }
    
    for(int i = 0; i < b.size()-1; ++i)
    {
        if(b[i] != b[i+1]) bb += b[i];
    }

    for(int i = 0; i < c.size()-1; ++i)
    {
        if(c[i] != c[i+1]) cc += c[i];
    }

    if(!(aa == bb && bb == cc))
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> va, vb, vc;
    int tmp = 1, ind = 0;
    while(ind < a.size()-1)
    {
        while(ind < a.size()-1 && a[ind] == a[ind+1])
        {
            tmp++;
            ind++;
        }
        va.push_back(tmp);
        tmp = 1;
        ind++;
    }

    tmp = 1, ind = 0;
    while(ind < b.size()-1)
    {
        while(ind < b.size()-1 && b[ind] == b[ind+1])
        {
            tmp++;
            ind++;
        }
        vb.push_back(tmp);
        tmp = 1;
        ind++;
    }

    tmp = 1, ind = 0;
    while(ind < c.size()-1)
    {
        while(ind < c.size()-1 && c[ind] == c[ind+1])
        {
            tmp++;
            ind++;
        }
        vc.push_back(tmp);
        tmp = 1;
        ind++;
    }

    vector<int> u;
    for(int i = 0; i < va.size(); ++i)
    {
        vector<int> l = {va[i], vb[i], vc[i]};
        sort(l.begin(), l.end());
        u.push_back(l[1]);
    }

    for(int i = 0; i < u.size(); ++i)
    {
        for(int j = 0; j < u[i]; ++j)
        {
            cout << aa[i];
        }
    }
 
}
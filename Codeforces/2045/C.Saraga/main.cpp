#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s, t; cin >> s >> t;

    vector<int> firstS(26, -1), lastT(26, -1);
    for(int i = s.size()-1; i > 0; i--)
        firstS[(s[i]-'a')] = i;
    for(int i = 0; i < t.size()-1; i++)
        lastT[(t[i]-'a')] = (t.size()-i-1);

    int mnn = 1e9, idx = -1;
    for(int i = 0; i < 26; i++)
    {
        if(firstS[i] != -1 && lastT[i] != -1 && firstS[i]+lastT[i] < mnn)
        {
            mnn = firstS[i]+lastT[i];
            idx = i;
        }
    }

    if(idx == -1)
    {
        cout << -1 << "\n";
    } else
    {
        cout << s.substr(0, firstS[idx]) + t.substr(t.size()-lastT[idx]-1, lastT[idx]+1) << "\n";
    }
}

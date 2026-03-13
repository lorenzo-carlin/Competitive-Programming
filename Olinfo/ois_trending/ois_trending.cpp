#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> vs;
    map<string, int> mp;
    int N; cin >> N;
    int T; cin >> T;
    for(int i = 0; i < N; ++i)
    {
        string word; cin >> word;
        vs.insert(vs.end(), word);
    }
    for(int i = 0; i < N; ++i)
    {
        mp.clear();
        for(int j = 0; j < T; ++j)
        {
            map<string,int>::iterator itr=mp.find(vs[i+j]);
            if(itr == mp.end())
            {
                mp.insert(make_pair(vs[i+j], 1));
            } else
            {
                mp[vs[i+j]]++;
            }
        }
        int mx = 0;
        int len = mp.size();
        for(int j = 0; j < len; ++j)
        {
            if(mp[vs[i+j]] > mx)
            {
                mx = mp[vs[i+j]];
            }
        }
        string ris = "zzzzzzzzzzzzzzzzzzzz";
        for(int j = 0; j < len; ++j)
        {
            if(mp[vs[i+j]] == mx && vs[i+j] < ris)
            {
                ris = vs[i+j];
            }
        }
        cout << ris << endl;
        if(i == (N - T))
        {
            break;
        }
    }
    return 0;
}
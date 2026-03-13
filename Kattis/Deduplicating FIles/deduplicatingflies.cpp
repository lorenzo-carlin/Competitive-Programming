#include <bits/stdc++.h>
using namespace std;

int stringhash(string s)
{
    int hash_ = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        hash_ ^= s[i];
    }
    return hash_;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string c;
    while(true)
    {
        int col = 0;
        set<string> unique_files;
        multiset<int> unique_hash;
        getline(cin, c);
        int t = stoi(c);
        if(t == 0)
        {
            break;
        }
        for(int i = 0; i < t; ++i)
        {
            string s;
            getline(cin,s);
            int h = stringhash(s);
            auto it = unique_hash.find(h);
            int tmp = unique_hash.count(h);
            if(it == unique_hash.end())
            {
                unique_hash.insert(h);
                unique_files.insert(s);
            } else
            {
                auto ind = unique_files.find(s);
                if(ind == unique_files.end())
                {
                    col += tmp;
                    unique_hash.insert(h);
                    unique_files.insert(s);
                } else
                {
                    col += (tmp-1);
                }
            }
        }
        cout << unique_files.size() << " " << col << endl;
    }
}
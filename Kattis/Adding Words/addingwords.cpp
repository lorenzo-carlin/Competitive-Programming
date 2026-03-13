#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    map<string, int> mp;
    string cmd;
    int c = 0;
    while(cin >> cmd)
    {
        if(cmd == "def")
        {
            string var;
            int nr;
            cin >> var;
            cin >> nr;
            map<string, int>::iterator itr=mp.find(var);
            if(itr == mp.end())
            {
                mp.insert(make_pair(var, nr));
            } else
            {
                mp[var] = nr;
            }
        } else if(cmd == "calc")
        {
            bool cond = true;
            string var;
            char op;
            cin >> var;
            map<string, int>::iterator itr=mp.find(var);
            if(itr == mp.end())
            {
                cond = false;
            }
            cout << var << " ";
            int count = mp[var];
            cin >> op;
            while(op != '=')
            {
                cout << op << " ";
                cin >> var;
                map<string, int>::iterator itr=mp.find(var);
                if(itr == mp.end())
                {
                    cond = false;
                }
                cout << var << " ";
                if(op == '+')
                {
                    count += mp[var];
                } else if(op == '-')
                {
                    count -= mp[var];
                }
                cin >> op;
            }
            if(cond)
            {
                bool t = true;
                for(auto& x: mp)
                {
                    if(x.second == count)
                    {
                        cout << "= " << x.first << endl;
                        t = false;
                    }
                }
                if(t)
                {
                    cout << "= unknown\n";
                }
            } else
            {
                cout << "= unknown\n";
            }
            c++;
        } else if(cmd == "clear")
        {
            mp.clear();
        }
    }
    return 0;
}
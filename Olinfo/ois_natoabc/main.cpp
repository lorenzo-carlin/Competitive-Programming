#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    set<string> s;
    s = {"alpha", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel", "india", "juliett", "kilo", "lima", "mike", "november", "oscar", "papa", "quebec", "romeo", "sierra", "tango", "uniform", "victor", "whiskey", "xray", "yankee", "zulu"};

    string st, fn, cur;
    cin >> st;

    for(int i = 0; i < st.size(); i++)
    {
        cur += st[i];
        if(s.count(cur))
        {
            fn += cur[0];
            cur = "";
        }
    }

    cout << fn << "\n";
}

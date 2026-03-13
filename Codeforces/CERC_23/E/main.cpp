#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    set<string> s;

    map<string,int> m1;
    string s1, s2, s3;
    cin >> s1;
    while(s1 != "------")
    {
        cin >> s2 >> s3;
        int st = stoi(s1), fn = stoi(s2);
        m1[s3] += (fn-st);
        s.insert(s3);

        cin >> s1;
    }

    map<string,int> m2;
    cin >> s1;
    while(s1 != "======")
    {
        cin >> s2 >> s3;
        int st = stoi(s1), fn = stoi(s2);
        m2[s3] += (fn-st);
        s.insert(s3);

        cin >> s1;
    }

    int cnt = 0;
    for(auto el: s)
    {
        int dif = m2[el]-m1[el];
        if(dif > 0)
        {
            cout << el << " +" << dif << "\n";
            cnt++;
        } else if(dif < 0)
        {
            cout << el << " -" << abs(dif) << "\n";
            cnt++;
        }
    }

    if(cnt == 0)
    {
        cout << "No differences found.\n";
    }
}

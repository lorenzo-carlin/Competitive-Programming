#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N1, N2;
    cin >> N1;
    cin >> N2;
    set<string> v1;
    for(int i = 0; i < N1; ++i)
    {
        string id; cin >> id;
        v1.insert(v1.end(), id);
    }
    int c = 0;
    for(int i = 0; i < N2; ++i)
    {
        string id; cin >> id;
        if(v1.find(id) != v1.end())
        {
            c++;
        }
    }
    cout << c;
    return 0;
}

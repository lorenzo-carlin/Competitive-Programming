#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<string> v(n);
    for(auto &i:v) cin >> i;

    map<string,int> codes;
    for(int i = 0; i < 10; ++i)
    {
        string a; cin >> a;
        codes[a] = i;
    }

    for(int i = 0; i < n; ++i)
    {
        string s = v[i];
        string tmp;
        for(int j = 0; j < s.length(); ++j)
        {
            tmp += s[j];
            auto it = codes.find(tmp);
            if(it != codes.end())
            {
                cout << codes[tmp];
                tmp.clear();
            }
        }
        cout << "\n";
    }
}
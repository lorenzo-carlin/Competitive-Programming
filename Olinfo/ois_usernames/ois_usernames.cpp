#include <bits/stdc++.h>
using namespace std;

int char_to_int(char c)
{
    int val;
    if(c >= 'a' && c <= 'z')
    {
        val = c - 'a';
    } else
    {
        val = c - '0' + ('z' - 'a' + 1);
    }
    return val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<string> vs(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> vs[i];
    }
    const int DIM = ('z' - 'a') + ('9' - '0') + 2;
    vector<bitset<DIM>> bs(n);
    for(int i = 0; i < n; ++i)
    {
        for(auto c : vs[i])
            bs[i].set(char_to_int(c));
    }
    int ris = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i != j && (bs[i] & bs[j]) == bs[i])
            {
                ris++;
            }
        }
    }
    cout << ris;
    return 0;

}
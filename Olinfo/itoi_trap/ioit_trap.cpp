#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, L;
    cin >> N >> L;
    vector<int> cnt;
    vector<string> fst_s;
    set<string> other;
    int m; cin >> m;
    for(int i = 0; i < m; ++i)
    {
        string word; cin >> word;
        fst_s.insert(fst_s.end(), word);
        cnt.insert(cnt.end(), 0);
    }
    for(int i = 0; i < N-1; ++i)
    {
        other.clear();
        int len; cin >> len;
        for(int j = 0; j < len; ++j)
        {
            string word; cin >> word;
            other.insert(other.end(), word);
        }
        for(int j = 0; j < m; ++j)
        {
            if(other.find(fst_s[j]) != other.end())
            {
                cnt[j]++;
            }
        }
        
    }
    for(int i = 0; i < m; ++i)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
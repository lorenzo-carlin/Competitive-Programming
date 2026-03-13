#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> pali;
    vector<int> pot = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

    auto generate = [&] (int n) -> void
    {
        if(n & 1)
        {
            for(int i = 1; i < pot[(n+1)/2]; i++)
            {
                if(i % 10 == 0) continue;
                string s = to_string(i);
                while(s.size() < (n+1)/2) s.insert(s.begin(), '0');
                char m = s[0];
                s.erase(s.begin());
                string r = s;
                reverse(begin(r), end(r));
                pali.push_back(stoi(r + m + s));
            }
        } else
        {
            for(int i = 1; i < pot[n/2]; i++)
            {
                if(i % 10 == 0) continue;
                string s = to_string(i);
                while(s.size() < n/2) s.insert(s.begin(), '0');
                string r = s;
                reverse(begin(r), end(r));
                pali.push_back(stoi(r + s));
            }
        }
    };

    for(int i = 1; i <= 7; i++)
        generate(i);

    sort(begin(pali), end(pali));

    int n; cin >> n;
    while(n--)
    {
        int a, b; cin >> a >> b;
        int ans = upper_bound(begin(pali), end(pali), b) - lower_bound(begin(pali), end(pali), a);
        cout << ans << "\n";
    }
}    

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int &i: v) cin >> i;
 
    set<pair<int,int>> s;
    for(int i = 0; i < k; ++i)
    {
        s.insert({v[i], i});
    }
 
    auto median = s.begin();
    for(int i = 0; i < (k-1)/2; i++)
    {
        median++;
    }
    cout << (*median).first << " ";
    for(int i = k; i < n; ++i)
    {
        int neww = v[i];
        int oldd = v[i-k];
        int med = (*median).first;
 
        s.insert({neww, i});
 
        if((*median).second == i-k)
        {
            if(neww >= oldd)
            {
                median++;
                while((*median).second <= (i-k))
                {
                    auto tmp = median;
                    median++;
                    s.erase(tmp);
                }
            } else
            {
                median--;
                while((*median).second <= (i-k))
                {
                    auto tmp = median;
                    median--;
                    s.erase(tmp);
                }
            }
        } else if(neww < med && oldd > med)
        {
            median--;
            while((*median).second <= (i-k))
            {
                auto tmp = median;
                median--;
                s.erase(tmp);
            }
        } else if(neww >= med && oldd <= med)
        {
            median++;
            while((*median).second <= (i-k))
            {
                auto tmp = median;
                median++;
                s.erase(tmp);
            }
        }
 
        cout << (*median).first << " ";
    }
 
    cout << "\n";
}

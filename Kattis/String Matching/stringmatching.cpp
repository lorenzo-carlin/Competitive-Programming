#include <iostream>
#include <string>
using namespace std;

string pattern, text, tmp;

int main()
{
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ind = 0;
    while(getline(cin, pattern))
    {
        getline(cin, text);
        ind = 0;
        tmp.clear();
        tmp += 'a';
        while(ind < pattern.size()-1)
        {
            tmp += text[ind];
            ind++;
        }
        for(int i = 0; i <= text.size()-pattern.size()+1; ++i)
        {
            tmp.erase(tmp.begin());
            tmp.push_back(text[i]);
            for(int j = 0; j < pattern.size(); ++j)
            {
                if(text[i+j] != pattern[j])
                {
                    break;
                }
                if(j == pattern.size()-1)
                {
                    cout << i << " ";
                }
            }
        }
        cout << "\n";
    }
}
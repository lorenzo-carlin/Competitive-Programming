#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    vector<bool> line(8, false), column(8, false), diag1(15, false), diag2(15, false);
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            char c; cin >> c;
            if(c == '*')
            {
                if(line[i] || column[j] || diag1[i+j] || diag2[j-i+7])
                {
                    cout << "invalid\n";
                    return 0;
                }
                line[i] = true;
                column[j] = true;
                diag1[i+j] = true;
                diag2[j-i+7] = true;
            }
        }
    }

    cout << "valid\n";
}
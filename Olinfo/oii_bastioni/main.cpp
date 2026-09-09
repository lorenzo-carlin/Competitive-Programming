#include <bits/stdc++.h>
using namespace std;
using ll = long long;

enum { ND, SX, DX };

int arrampicate(int N, string S)
{
    bool cond = false;
    int st = -1;
    for(int i = 0; i < N; ++i)
    {
        if(S[i] == '?' && !cond)
        {
            cond = true;
            st = i;
        }
        if(S[i] == '?' && S[i+1] != '?')
        {
            cond = false;
            // casi in cui parto dall'inizio
            if(i == N-1 || (st > 0 && i < N-1 && (S[i+1] == '=' || S[i+1] == '#')))
            {
                for(int j = st; j <= i; ++j)
                {
                    if(S[j] != '?') continue;
                    if(S[j-1] == '=' || S[j-1] == '#') S[j] = '>';
                    else if(S[j-1] == '<') S[j] = '>';
                    else if(S[j-1] == '>') S[j] = '<';
                    if(j == st && (i-st+1)%2==0) S[j+1] = S[j];
                }
            } else
            {
                // parto dalla fine
                for(int j = i; j >= st; j--)
                {
                    if(S[j] != '?') continue;
                    if(S[j+1] == '=' || S[j+1] == '#') S[j] = '>';
                    else if(S[j+1] == '<') S[j] = '>';
                    else if(S[j+1] == '>') S[j] = '<';
                    if(j == i && (i-st+1)%2==0) S[j-1] = S[j];
                }
            }
        }
    }

    // for(int i = 0; i < N; ++i)
    // {
    //     cout << S[i];
    // }
    // cout << "\n";


    vector<int> v(N+1);
    v[0] = ND;
    int sol = 1;
    for(int i = 0; i < N; ++i)
    {
        if(S[i] == '#' || (v[i] == SX && S[i] == '>') || (v[i] == DX && S[i] == '<'))
        {
            v[i+1] = ND;
            sol++;
        } else if(v[i] == SX && S[i] == '>') v[i+1] = ND;
        else if(v[i] == DX && S[i] == '<') v[i+1] = ND;
        else if((v[i] == SX || v[i] == ND) && S[i] == '<') v[i+1] = SX;
        else if((v[i] == DX || v[i] == ND) && S[i] == '>') v[i+1] = DX;
        else if(S[i] == '=') v[i+1] = v[i];
    }

    return sol;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    string S; cin >> S;

    cout << arrampicate(N, S) << "\n";
}
#include <bits/stdc++.h>
using namespace std;

vector<int> v;
string uno = "[O]";
string due = "[OOOO]";


void stampa()
{
    for(int i = 0; i < v.size(); ++i)
    {
        if(v[i] == 1)
        {
            cout << uno;
        } else if(v[i] == 2)
        {
            cout << due;
        }
    }
    cout << endl;
}

void piastrelle(int num)
{
    if(num == 0)
        return;
    if(num == 1)
    {
        v.push_back(1);
        stampa();
        v.pop_back();
    } else if(num == 2)
    {
        v.push_back(1);
        piastrelle(num-1);
        v.pop_back();
        v.push_back(2);
        stampa();
        v.pop_back();
    } else
    {
        v.push_back(1);
        piastrelle(num-1);
        v.pop_back();
        v.push_back(2);
        piastrelle(num-2);
        v.pop_back();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    piastrelle(n);
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool alive = false;
    bool undead = false;

    string s; getline(cin, s);
    char pred, curr;
    pred = 'a';
    for(char el: s)
    {
        curr = el;
        if(pred == ':' && curr == ')')
        {
            alive = true;
        } else if(pred == ':' && curr == '(')
        {
            undead = true;
        }
        pred = curr;
    }
    if(alive && undead)
    {
        cout << "double agent\n";
    } else if(alive)
    {
        cout << "alive\n";
    } else if(undead)
    {
        cout << "undead\n";
    } else
    {
        cout << "machine\n";
    }
}
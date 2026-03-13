#include <bits/stdc++.h>
using namespace std;

void Vernicia(int indice, int colore);

void Diversifica(int N, int colore[]) {
    set<int> thereis, pos;
    for(int i = 0; i < N; i++)
    {
        if(thereis.count(colore[i]) > 0)
        {
            pos.insert(i);
        } else
        {
            thereis.insert(colore[i]);
        }
    }
    queue<int> thereisnt;
    for(int i = 1; i <= N; i++)
    {
        if(thereis.count(i) == 0) thereisnt.push(i);
    }

    for(auto el: pos)
    {
        Vernicia(el, thereisnt.front());
        thereisnt.pop();
    }
}

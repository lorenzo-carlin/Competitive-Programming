#include <bits/stdc++.h>
using namespace std;

int scarta(int M, vector<bool> L, vector<bool> D, vector<bool> N){
    int ans = 0;
    for(int i = 0; i < M; ++i)
    {
        if(((L[i] == true) && (D[i] == true) && (N[i] == true)) || ((L[i] == false) && (D[i] == false) && (N[i] == false)) || ((L[i] == true) && (D[i] == true) && (N[i] == false)) || ((L[i] == true) && (D[i] == false) && (N[i] == true)) || ((L[i] == false) && (D[i] == true) && (N[i] == true)))
        {
            ans++;
        }
    }
	return ans;
}
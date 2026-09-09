#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

int pulisci(int n, int m, vector<string> s)
{
	vector<int> righe(n), colonne(m);
	for(int i = 0; i < n; ++i)
	{
		string tmp = s[i];
		for(int j = 0; j < tmp.size(); ++j)
		{
			if(tmp[j] == '1')
			{
				righe[i]++;
				colonne[j]++;
			}
		}
	}

	multiset<int> R, C;
	for(int i = 0; i < n; ++i) R.insert(righe[i]);
	for(int i = 0; i < m; ++i) C.insert(colonne[i]);

	int targetR = m, targetC = n;
	int zeroR = 0, zeroC = 0;

	bool stop = false;
	int eliminati = 0;
	int rimrighe = m, rimcolonne = n;
	while(!stop)
	{
		if(R.count(targetR))
		{
			eliminati += rimrighe;
			rimcolonne--;
			auto it = R.find(targetR);
			R.erase(it);
			zeroC++;
		} else if(C.count(targetC))
		{
			eliminati += rimcolonne;
			rimrighe--;
			auto it = C.find(targetC);
			C.erase(it);
			zeroR++;
		} else if(R.count(zeroR))
		{
			eliminati += rimrighe;
			rimcolonne--;
			targetC--;
			auto it = R.find(zeroR);
			R.erase(it);
		} else if(C.count(zeroC))
		{
			eliminati += rimcolonne;
			rimrighe--;
			targetR--;
			auto it = C.find(zeroC);
			C.erase(it);
		} else
		{
			stop = true;
		}
	}

	int sol = n*m - eliminati;
	return sol;
}

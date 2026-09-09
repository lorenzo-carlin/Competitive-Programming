#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> cucina(int n, int k, int x, vector<int> h)
{
	vector<int> nuovi_arrivi(x, 0);
	for(int i = 0; i < n; ++i)
	{
		nuovi_arrivi[h[i]]++;
	}

	vector<int> ans(x+1, 0);
	int nr_posti_occupati = k-1; // 0
	int nr_concorrenti_aggiunti = 0; // 1
	for(int i = x-1; i >= 0; i--)
	{
		nr_concorrenti_aggiunti = min(nuovi_arrivi[i], k - nr_posti_occupati);
		nr_posti_occupati = max(0, nr_posti_occupati+nr_concorrenti_aggiunti-1);
		ans[i] = ans[i+1]+nr_concorrenti_aggiunti;
	}

	ans.pop_back();
	return ans;
}

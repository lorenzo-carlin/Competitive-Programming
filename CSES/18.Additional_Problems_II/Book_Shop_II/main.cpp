#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<int> price, pages;
vector<int> pot = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
 
void convert(int h, int s, int k)
{
	if(k == 0) return;
 
	int i;
	for(i = 1; i < pot.size(); ++i)
	{
		if(k < pot[i]-1) break;
	}
 
	i--;
	int rem = k - (pot[i]-1);
	i--;
 
	while(i >= 0)
	{
		//cout << pot[i] << " ";
		price.push_back(pot[i]*h);
		pages.push_back(pot[i]*s);
		i--;
	}
	convert(h, s, rem);
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, x; cin >> n >> x;
	vector<int> h(n), s(n), k(n);
	for(int &i: h) cin >> i;
	for(int &i: s) cin >> i;
	for(int &i: k) cin >> i;
	for(int i = 0; i < n; ++i)
	{
		convert(h[i], s[i], k[i]);
	}
	
	/*
	cout << "pages: ";
	for(int el: pages) cout << el << " ";
	cout << "\n";
	cout << "price: ";
	for(int el: price) cout << el << " ";
	cout << "\n";
	*/
 
	int sz = pages.size();
	vector<int> dp(x+1, 0), last(x+1, 0);
	for(int i = 1; i <= sz; ++i)
	{
		last = dp;
		for(int j = 1; j <= x; ++j)
		{
			dp[j] = last[j];
			if(j - price[i-1] >= 0)
			{
				dp[j] = max(dp[j], last[j - price[i-1]]+pages[i-1]);
			}
		}
		/*
		for(int el: dp) cout << el << " ";
		cout << "\n";
		*/
	}
	cout << dp[x] << "\n";
}

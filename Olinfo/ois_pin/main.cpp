#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char convert(int num)
{
	if(num == 0) return '0';
	if(num == 1) return '1';
	if(num == 2) return '2';
	if(num == 3) return '3';
	if(num == 4) return '4';
	if(num == 5) return '5';
	if(num == 6) return '6';
	if(num == 7) return '7';
	if(num == 8) return '8';
	return '9';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;
	string s;
	for(int i = 0, c; i < n; ++i)
	{
		cin >> c;
		s.push_back(convert(c));
	}

	map<string,int> mp;
	for(int i = 0; i < n-k+1; i++)
	{
		string cur = s.substr(i, k);
		mp[cur]++;
	}

	string smax;
	int mx = 0;
	for(auto el: mp)
	{
		if(el.second > mx)
		{
			mx = el.second;
			smax = el.first;
		}
	}

	for(int i = 0; i < k; ++i) cout << smax[i] << " ";
	cout << "\n";
}

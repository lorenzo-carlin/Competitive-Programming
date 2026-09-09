#include <bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<str,int> name_occ;
	map<int,set<str>> occ_names;
	deque<str> d;
	str s;

	auto add = [&] (str s) -> void
	{
		if(!name_occ.count(s))
		{
			name_occ[s] = 0;
			occ_names[0].insert(s);
		}
		int prec = name_occ[s];
		occ_names[-prec].erase(s);
		if(occ_names[-prec].empty()) occ_names.erase(-prec);
		int curr = prec+1;
		occ_names[-curr].insert(s);
		name_occ[s] = curr;
	};

	auto remove = [&] (str s) -> void
	{
		int prec = name_occ[s];
		occ_names[-prec].erase(s);
		if(occ_names[-prec].empty()) occ_names.erase(-prec);
		int curr = prec-1;
		occ_names[-curr].insert(s);
		name_occ[s] = curr;
	};

	auto print = [&] () -> void
	{
		auto it = occ_names.begin();
		auto it2 = (*it).second.begin();
		cout << *it2 << "\n";
	};

	int n, t; cin >> n >> t;
	for(int i = 0; i < t; ++i)
	{
		cin >> s;
		d.push_back(s);
		add(s);
	}
	print();

	for(int i = t; i < n; ++i)
	{
		cin >> s;
		str rem = d.front();
		d.pop_front();
		d.push_back(s);

		remove(rem);
		add(s);
		print();
	}
}

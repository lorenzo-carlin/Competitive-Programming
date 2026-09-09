#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

ll inv = 0;

void merge_sort(vector<int> &a)
{
	if(a.size() == 1) return;

	int n = a.size();
	int dimLeft = (n+1)/2;
	int dimRight = n/2;
	vector<int> left(dimLeft), right(dimRight);
	for(int i = 0; i < dimLeft; ++i) left[i] = a[i];
	for(int i = 0; i < dimRight; ++i) right[i] = a[i+dimLeft];

	merge_sort(left);
	merge_sort(right);

	left.push_back(INT_MAX);
	right.push_back(INT_MAX);
	int l = 0, r = 0;
	for(int i = 0; i < n; ++i)
	{
		if(left[l] < right[r])
		{
			a[i] = left[l];
			l++;
		} else
		{
			inv += (dimLeft-l);
			a[i] = right[r];
			r++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i];

	vector<int> Sa(n-1), Sb(n-1);
	for(int i = 0; i < n-1; ++i)
	{
		Sa[i] = (i % 2) ? (-a[i]-a[i+1]) : (a[i]+a[i+1]);
		Sb[i] = (i % 2) ? (-b[i]-b[i+1]) : (b[i]+b[i+1]);
	}

	// for(int el: Sa) cout << el << " ";
	// cout << "\n";
	// for(int el: Sb) cout << el << " ";
	// cout << "\n";
	
	if(a[0] != b[0])
	{
		cout << -1 << "\n";
		return 0;
	}

	vector<int> A = Sa;
	vector<int> B = Sb;
	sort(begin(A), end(A));
	sort(begin(B), end(B));
	for(int i = 0; i < n-1; ++i)
	{
		if(A[i] != B[i])
		{
			cout << -1 << "\n";
			return 0;
		}
	}

	map<int,deque<int>> mp;
	for(int i = 0; i < n-1; ++i)
	{
		mp[Sb[i]].push_back(i);
	}
	for(int i = 0; i < n-1; ++i)
	{
		int tmp = Sa[i];
		Sa[i] = mp[Sa[i]].front();
		mp[tmp].pop_front();
	}

	merge_sort(Sa);
	cout << inv << "\n";
}

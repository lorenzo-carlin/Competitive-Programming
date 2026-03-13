#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int calcolo_di_una_permutazione(array<int,3> per, int n, vector<int> &a, vector<int> &b, vector<int> &c)
{
	set<int> s;
	int x = 0, y = 0, z = 0;
	int ans = 0;

	// creo la situazione iniziale (massimo X)
	for(int i = 0; i < 3; ++i)
	{
		if(per[i] == 1)
		{
			while(x < n && !s.count(a[x]))
			{
				s.insert(a[x]);
				x++;
			}
		} else if(per[i] == 2)
		{
			while(y < n && !s.count(b[y]))
			{
				s.insert(b[y]);
				y++;
			}
		} else if(per[i] == 3)
		{
			while(z < n && !s.count(c[z]))
			{
				s.insert(c[z]);
				z++;
			}
		}
	}
	ans = max(ans, (int)s.size());

	// decremento X
	if(per[0] == 1)
	{
		for(int i = x-1; i >= 0; i--)
		{
			s.erase(a[i]);
			if(per[1] == 2)
			{
				while(y < n && !s.count(b[y]))
				{
					s.insert(b[y]);
					y++;
				}
				while(z < n && !s.count(c[z]))
				{
					s.insert(c[z]);
					z++;
				}
			} else if(per[1] == 3)
			{
				while(z < n && !s.count(c[z]))
				{
					s.insert(c[z]);
					z++;
				}
				while(y < n && !s.count(b[y]))
				{
					s.insert(b[y]);
					y++;
				}
			}
			ans = max(ans, (int)s.size());
		}
	} else if(per[0] == 2)
	{
		for(int i = y-1; i >= 0; i--)
		{
			s.erase(b[i]);
			if(per[1] == 1)
			{
				while(x < n && !s.count(a[x]))
				{
					s.insert(a[x]);
					x++;
				}
				while(z < n && !s.count(c[z]))
				{
					s.insert(c[z]);
					z++;
				}
			} else if(per[1] == 3)
			{
				while(z < n && !s.count(c[z]))
				{
					s.insert(c[z]);
					z++;
				}
				while(x < n && !s.count(a[x]))
				{
					s.insert(a[x]);
					x++;
				}
			}
			ans = max(ans, (int)s.size());
		}
	} else if(per[0] == 3)
	{
		for(int i = z-1; i >= 0; i--)
		{
			s.erase(c[i]);
			if(per[1] == 1)
			{
				while(x < n && !s.count(a[x]))
				{
					s.insert(a[x]);
					x++;
				}
				while(y < n && !s.count(b[y]))
				{
					s.insert(b[y]);
					y++;
				}
			} else if(per[1] == 2)
			{
				while(y < n && !s.count(b[y]))
				{
					s.insert(b[y]);
					y++;
				}
				while(x < n && !s.count(a[x]))
				{
					s.insert(a[x]);
					x++;
				}
			}
			ans = max(ans, (int)s.size());
		}
	}

	return ans;
}

int conta(int n, vector<int> &a, vector<int> &p, vector<int> &d)
{
	int sol = 0;
	sol = max(sol, calcolo_di_una_permutazione({1, 2, 3}, n, a, p, d));
	sol = max(sol, calcolo_di_una_permutazione({1, 3, 2}, n, a, p, d));
	sol = max(sol, calcolo_di_una_permutazione({2, 1, 3}, n, a, p, d));
	sol = max(sol, calcolo_di_una_permutazione({2, 3, 1}, n, a, p, d));
	sol = max(sol, calcolo_di_una_permutazione({3, 1, 2}, n, a, p, d));
	sol = max(sol, calcolo_di_una_permutazione({3, 2, 1}, n, a, p, d));
	return sol;
}

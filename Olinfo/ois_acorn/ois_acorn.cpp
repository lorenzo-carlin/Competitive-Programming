#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int x, y;

bool check()
{
	if((x == 0 && y == 1) || (x == 1 && y == 0))
	{
		return true;
	}
	return false;
}

void win()
{
	if(check()) return;

	if(x > y && y % 2 == 0)
	{
		cout << y+1 << " " << y << "\n";
		x = y+1;
	} else if(x > y && y % 2 == 1)
	{
		cout << y-1 << " " << y << "\n";
		x = y-1;
	} else if(y > x && x % 2 == 0)
	{
		cout << x << " " << x+1 << "\n";
		y = x+1;
	} else if(y > x && x % 2 == 1)
	{
		cout << x << " " << x-1 << "\n";
		y = x-1;
	}

	if(check()) return;

	cin >> x >> y;
	win();
}

void lose()
{
	if(check()) return;

	cin >> x >> y;

	if(check()) return;

	if(x > y && y % 2 == 0)
	{
		cout << y+1 << " " << y << "\n";
		x = y+1;
	} else if(x > y && y % 2 == 1)
	{
		cout << y-1 << " " << y << "\n";
		x = y-1;
	} else if(y > x && x % 2 == 0)
	{
		cout << x << " " << x+1 << "\n";
		y = x+1;
	} else if(y > x && x % 2 == 1)
	{
		cout << x << " " << x-1 << "\n";
		y = x-1;
	}

	if(check()) return;

	lose();
}

int main()
{
	cin >> x >> y;
	if((y == x+1 && x % 2 == 0) || (x == y+1 && y % 2 == 0))
	{
		cout << "N\n";
		lose();
	} else
	{
		cout << "C\n";
		win();
	}
}

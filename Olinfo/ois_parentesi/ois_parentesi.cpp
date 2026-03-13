#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	stack<char> s;
	for(int i = 0; i < n; ++i)
	{
		char c; cin >> c;
		if(c == '>' && !s.empty() && s.top() == '<') s.pop();
		else if(c == ')' && !s.empty() && s.top() == '(') s.pop();
		else if(c == ']' && !s.empty() && s.top() == '[') s.pop();
		else if(c == '}' && !s.empty() && s.top() == '{') s.pop();
		else s.push(c);
	}

	if(s.empty()) cout << "corretta\n";
	else cout << "malformata\n";
}

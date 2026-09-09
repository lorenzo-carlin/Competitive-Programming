#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	string ans = "-----";
	vector<char> giuste;

	auto guess = [&] (string s) -> void
	{
		cout << "? " << s << "\n";
		string S; cin >> S;
		for(int i = 0; i < 5; ++i)
		{
			if(S[i] == 'Y') giuste.push_back(s[i]);
			else if(S[i] == 'G')
			{
				giuste.push_back(s[i]);
				ans[i] = s[i];
			}
		}
		// fflush(stdout);
	};
	
	auto create_string = [&] (char c) -> string
	{
		string ans;
		ans += c; ans += c; ans += c; ans += c; ans += c;
		return ans;
	};

	// guess iniziali
	string a = "abcde";
	guess(a);
	string b = "fghij";
	guess(b);
	string c = "klmno";
	guess(c);
	string d = "pqrst";
	guess(d);
	string e = "uvwxy";
	guess(e);

	if(giuste.size() == 0)
	{
		cout << "! zzzzz\n";
	} else if(giuste.size() == 1)
	{
		string f = create_string(giuste[0]);
		guess(f);
		for(int i = 0; i < 5; ++i) if(ans[i] == '-') ans[i] = 'z';
		cout << "! " << ans << "\n";
	} else if(giuste.size() == 2)
	{
		string f = create_string(giuste[0]);
		guess(f);
		string g = create_string(giuste[1]);
		guess(g);
		for(int i = 0; i < 5; ++i) if(ans[i] == '-') ans[i] = 'z';
		cout << "! " << ans << "\n";
	} else if(giuste.size() == 3)
	{
		string f = create_string(giuste[0]);
		guess(f);
		string g = create_string(giuste[1]);
		guess(g);
		string h = create_string(giuste[2]);
		guess(h);
		for(int i = 0; i < 5; ++i) if(ans[i] == '-') ans[i] = 'z';
		cout << "! " << ans << "\n";
	} else if(giuste.size() == 4)
	{
		string f = create_string(giuste[0]);
		guess(f);
		string g = create_string(giuste[1]);
		guess(g);
		string h = create_string(giuste[2]);
		guess(h);
		string i = create_string(giuste[3]);
		guess(i);
		for(int i = 0; i < 5; ++i) if(ans[i] == '-') ans[i] = 'z';
		cout << "! " << ans << "\n";
	} else
	{
		string f = create_string(giuste[0]);
		guess(f);
		string g = create_string(giuste[1]);
		guess(g);
		string h = create_string(giuste[2]);
		guess(h);
		string i = create_string(giuste[3]);
		guess(i);
		for(int i = 0; i < 5; ++i) if(ans[i] == '-') ans[i] = giuste[4];
		cout << "! " << ans << "\n";
	}
	fflush(stdout);

}
		
int main()
{
	int t; cin >> t;
	while(t--) solve();
}

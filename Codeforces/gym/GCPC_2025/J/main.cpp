#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string t; cin >> t;
    int n; cin >> n;
    string s; cin >> s;

    int zero = 0, uno = 0, due = 0;
    for(int i = 0; i < n; i++)
    {
        zero += (s[i] == '0');
        uno += (s[i] == '1');
        due += (s[i] == '2');
    }

    if(t == "Encode")
    {
        string encoded;
        if(zero == n)
        {
            encoded = s;
        } else
        {
            int idx = 0;
            while(s[idx] == '0')
            {
                encoded += '2';
                idx++;
            }
            encoded += '2';
            idx++;
            while(idx < n)
            {
                encoded += s[idx];
                idx++;
            }
        }

        cout << encoded << "\n";
    } else
    {
        string decoded;
        if(zero == n)
        {
            decoded = s;
        } else
        {
            int st = 0;
            if(s[0] == '2' && due != n)
            {
                while(s[st] == '2')
                {
                    st++;
                }
            }

            while(st < n && s[st] != '2')
            {
                st++;
                st %= n;
            }

            while(decoded.size() < n && s[st] == '2')
            {
                decoded += '0';
                st++;
                st %= n;
            }
            decoded.pop_back();
            decoded += '1';
            while(decoded.size() < n)
            {
                decoded += s[st];
                st++;
                st %= n;
            }
        }

        cout << decoded << "\n";
    }
}

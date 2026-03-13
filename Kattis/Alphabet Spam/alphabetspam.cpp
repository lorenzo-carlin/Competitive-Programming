#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string st; cin >> st;
    int whitespaces = 0, lowercase = 0, uppercase = 0, symbols = 0;
    for(auto el:st)
    {
        if(el == '_')
        {
            whitespaces++;
        } else if(!isalpha(el))
        {
            symbols++;
        } else if(isupper(el))
        {
            uppercase++;
        } else
        {
            lowercase++;
        }
    }
    int sz = st.size();
    double w = (double) whitespaces / sz;
    double l = (double) lowercase / sz;
    double u = (double) uppercase / sz;
    double s = (double) symbols / sz;
    cout << fixed << setprecision(6) << w << "\n" << l << "\n" << u << "\n" << s << "\n";
}
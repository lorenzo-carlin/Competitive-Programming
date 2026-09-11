#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T; cin >> T;
    for(int p = 1; p <= T; ++p)
    {
        int n1, n2, n3, n4; cin >> n1 >> n2 >> n3 >> n4;
        int M; cin >> M;
        string f1, f2, f3, f4; cin >> f1 >> f2 >> f3 >> f4;
        bool cond = false;
        for(int i = 0; i < n1; ++i)
        {
            if(cond)
                break;
            string tmp1 = f1.substr(i, M);
            for(int j = 0; j < n2; ++j)
            {
                if(cond)
                    break;
                string tmp2 = f2.substr(j, M);
                if(tmp1.compare(tmp2) == 0)
                {
                    for(int k = 0; k < n3; ++k)
                    {
                        if(cond)
                            break;
                        string tmp3 = f3.substr(k, M);
                        if(tmp2.compare(tmp3) == 0)
                        {
                            for(int x = 0; x < n4; ++x)
                            {
                                if(cond)
                                    break;
                                string tmp4 = f4.substr(x, M);
                                if(tmp3.compare(tmp4) == 0)
                                {
                                    cout << "Case #" << p << ": " << i << " " << j << " " << k << " " << x << endl;
                                    cond = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
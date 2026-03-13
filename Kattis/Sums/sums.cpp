#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    long long int vec[T];
    for(int i = 0; i < T; i++)
    {
        cin >> vec[i];
    }
    for(int i = 0; i < T; i++)
    {
        int l = 0;
        if(vec[i] % 2 != 0 && vec[i] > 1)
        {
            int v[2];
            v[0] = vec[i] / 2;
            v[1] = v[0] + 1;
            cout << vec[i] << " = " << v[0] << " + " << v[1] << endl;
            l++;
        } else
        {
            for(int j = 3; j <= vec[i] / 2; j++)
            {
                double p = vec[i] / j;
                if((j % 2 != 0) && (p % 1.0 == 0))
                {
                    int v[j];
                    v[0] = p - (j / 2);
                    cout << vec[i] << " = " << vec[0] << " + ";
                    for(int k = 1; k < j - 1; k++)
                    {
                        v[k] = v[k - 1] + 1;
                        cout << v[k] << " + ";
                    }
                    v[j - 1] = v[j - 2] + 1;
                    cout << v[j - 1] << endl;
                    break;
                } else if(j % 2 == 0 && p % 1.0 == 0.5)
                {
                    int v[j];
                    v[0] = p - (j / 2);
                    cout << vec[i] << " = " << vec[0] << " + ";
                    for(int k = 1; k < j - 1; k++)
                    {
                        v[k] = v[k - 1] + 1;
                        cout << v[k] << " + ";
                    }
                    v[j - 1] = v[j - 2] + 1;
                    cout << v[j - 1] << endl;
                    break;
                }

                /*
                float p = vec[i] / j;
                int v[j];
                float m = j / 2;
                int c;
                if(j % 2 == 0)
                {
                    c = p - m + 1.0;
                } else
                {
                    c = p - m;
                }
                int sum = 0;
                for(int k = 0; k < j; k++)
                {
                    v[k] = c;
                    c++;
                    sum = sum + v[k];
                }
                if(sum == vec[i])
                {
                    cout << vec[i] << " = ";
                    for(int k = 0; k < j - 1; k++)
                    {
                        cout << v[k] << " + ";
                    }
                    cout << v[j - 1] << endl;
                    l++;
                    break;
                */
            }
        }
        }
        if(l == 0)
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

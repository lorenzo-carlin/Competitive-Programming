/*
14
25 24
4 3 1 2
13 9 4 11
10 20 8 7
32 10 21
23 13 19 32 22
19 12 5 14 17 30
14 6 15 16
30 18 31 29
24 23 26
26 27 28
-1
*/

#include <bits/stdc++.h>
using namespace std;

char scan(int &n) {
	n = 0;
	bool neg = false;
	char c = getchar();
	while (!(c == '-' || (c >= '0' && c <= '9'))) { c = getchar(); }
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; !feof(stdin) && c >= '0' && c <= '9'; c = getchar()) {
		n = n * 10 + c - '0';
	}
	if (neg) { n *= -1; }
}

int main()
{
    unordered_map<int, list<int>> T;
    int K; cin >> K; //posizione a cui si trova il gattino
    int n = 0;
    int m;
    char c;
    c = scan(K);

    //Lettura dell'input e inizializzazione dell'albero

    while(n != -1) {
        c = scan(n); // n = primo numero della riga
        while(c != '\n')
        {
            c = scan(m); // m = figlio di n, c = blank char;
            T[n].push_front(m);
        }
    }

}
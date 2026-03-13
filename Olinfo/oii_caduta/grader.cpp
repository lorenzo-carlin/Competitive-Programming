#include <bits/stdc++.h>
using namespace std;

typedef enum {
	OK,
	RISOLTO,
	IMPOSSIBILE
} stato_t;

typedef struct {
	int domino1;
	int domino2;
} coppia_t;

bool valid(vector<int> v)
{
	int last_to_fall = v[0]-1;
	bool cond = true;
	for(int i = 1; i < v.size(); ++i)
	{
		if(i > last_to_fall)
		{
			cond = false;
		}
		last_to_fall = max(last_to_fall, (v[i]-1)+i);
	}
	return cond;
}

stato_t correggi(int N, int altezze[], coppia_t* scambio)
{
	vector<int> v(N);
	for(int i = 0; i < N; ++i) v[i] = altezze[i];

	if(valid(v)) return OK;
	for(int i = 0; i < N; ++i)
	{
		for(int j = i+1; j < N; ++j)
		{
			swap(v[i], v[j]);
			if(valid(v))
			{
				scambio->domino1 = i;
				scambio->domino2 = j;
				return RISOLTO;
			}
			swap(v[i], v[j]);
		}
	}
	return IMPOSSIBILE;
}

int main() {
	int N, *altezze;

	assert(1 == scanf("%d", &N));

	altezze = (int*) malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
		assert(1 == scanf("%d", &altezze[i]));

	coppia_t scambio;
	stato_t stato = correggi(N, altezze, &scambio);

	if (stato == OK)
		printf("OK\n");
	else if (stato == IMPOSSIBILE)
		printf("IMPOSSIBILE\n");
	else
		printf("%d %d\n", scambio.domino1, scambio.domino2);

	free(altezze);
	return EXIT_SUCCESS;
}

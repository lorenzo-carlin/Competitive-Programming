#include <bits/stdc++.h>
using namespace std;

enum{
    Up, Right, Down, Left, Start
};

const int MAX = 209;        // dimensione massima matrice (basta 199 ma meglio un po' di più)
bool solved = false;        // variabile che mi dice se ho trovato una via di fuga
string res, buffer;         // stringhe che ricevono l'input
bool visited[MAX][MAX];     // matrice dei visitati

int opposite_dir(int dir)   // calcola l'opposto di una direzione (es. Up -> Down, Left -> Right, ...)
{
    return (dir+2)%4;
}

void maze(int x, int y, int move)
{
    // segno la cella come visitata, in realtà la stiamo ancora visitando: non voglio ricapitarci sopra (si creerebbero loop infiniti)
    visited[x][y] = true;

    // vado in alto se posso, ovvero se prima non sono andato in basso e se non ho già visitato la cella in alto
    if(move != opposite_dir(Up) && !visited[x-1][y])
    {
        cout << "up\n" << flush;
        cin >> res;
        if(res == "solved")
        {
            solved = true;
        } else if(res == "ok")
        {
            maze(x-1, y, Up);       // visito la cella in alto
            if(solved) return;      // se ho trovato una via di fuga esco dalla funzione
            // torno indietro con il 'cursore immaginario'
            cout << "down\n" << flush;
            cin >> buffer;
            /*
            la variabile buffer restituisce sempre 'ok', perché torno nella cella da
            cui sono venuto (sicuramente non c'è un muro se ci sono appena passato)
            */
        }
    }

    // stesso ragionamento per le altre direzioni
    // vado a destra (se posso)
    if(move != opposite_dir(Right) && !visited[x][y+1])
    {
        cout << "right\n" << flush;
        cin >> res;
        if(res == "solved")
        {
            solved = true;
        } else if(res == "ok")
        {
            maze(x, y+1, Right);
            if(solved) return;
            cout << "left\n" << flush;
            cin >> buffer;
        }
    }

    // vado in basso (se posso)
    if(move != opposite_dir(Down) && !visited[x+1][y])
    {
        cout << "down\n" << flush;
        cin >> res;
        if(res == "solved")
        {
            solved = true;
        } else if(res == "ok")
        {
            maze(x+1, y, Down);
            if(solved) return;
            cout << "up\n" << flush;
            cin >> buffer;
        }
    }

    // vado a sinistra (se posso)
    if(move != opposite_dir(Left) && !visited[x][y-1])
    {
        cout << "left\n" << flush;
        cin >> res;
        if(res == "solved")
        {
            solved = true;
        } else if(res == "ok")
        {
            maze(x, y-1, Left);
            if(solved) return;
            cout << "right\n" << flush;
            cin >> buffer;
        }
    }

    /*
    Se sono arrivato a questo punto sicuramente non c'è via d'uscita, perché 'Start'
    è una mossa attribuita solo alla prima cella visitata e se ho visitato la prima
    cella in tutte le sue direzioni senza trovare soluzione allora non c'è un'uscita.
    */
    if(move == Start)
    {
        cout << "no way out\n" << flush;
    }
    return;
}


int main()
{
    // comando che in teoria velocizza l'input (non è necessario, accellera il codice di solo 0.01s)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // coordinate iniziali
    int x = 105, y = 105;

    // inizializzazione della matrice a 'false'
    for(int i = 0; i < MAX; ++i)
    {
        for(int j = 0; j < MAX; ++j)
        {
            visited[i][j] = false;
        }
    }

    // risoluzione
    maze(x, y, Start);
}
#include <iostream>
#include <vector>
using namespace std;

const int N = 3;

// Controlla se un giocatore ha vinto
char checkWin(const vector<vector<char>> &board) {
    for (int i = 0; i < N; ++i) {
        if (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0];
        if (board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i];
    }
    if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
    if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];
    return '.';
}

// Funzione ricorsiva per determinare se X può forzare la vittoria
bool canForceWin(vector<vector<char>> &board, bool turnX) {
    char winner = checkWin(board);
    if (winner == 'X') return true;
    if (winner == 'O') return false;
    
    bool hasEmpty = false;
    bool canWin = turnX ? false : true;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == '.') {
                hasEmpty = true;
                board[i][j] = turnX ? 'X' : 'O';
                bool result = canForceWin(board, !turnX);
                board[i][j] = '.'; // Ripristina lo stato
                
                if (turnX && result) return true;
                if (!turnX && !result) canWin = false;
            }
        }
    }
    
    return hasEmpty ? canWin : false;
}

int main() {
    vector<vector<char>> board(N, vector<char>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }
    
    if (canForceWin(board, true)) {
        cout << "X può forzare la vittoria" << endl;
    } else {
        cout << "X non può forzare la vittoria" << endl;
    }
    
    return 0;
}


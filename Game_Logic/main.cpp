#include <iostream>

using namespace std;

// Constants for board size
const int BOARD_SIZE = 4;

// Function to display the current board state
void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    cout << "Tic-Tac-Toe Board:" << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j];
            if (j < BOARD_SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < BOARD_SIZE - 1) cout << "-----------------" << endl;
    }
    cout << endl;
}

// Function to initialize the board with empty spaces
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to make a move
bool makeMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char player) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

// Function to check if a player has won
bool checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        bool rowWin = true;
        bool colWin = true;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != player) rowWin = false;
            if (board[j][i] != player) colWin = false;
        }
        if (rowWin || colWin) return true;
    }

    // Check diagonals
    bool diag1Win = true;
    bool diag2Win = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] != player) diag1Win = false;
        if (board[i][BOARD_SIZE - i - 1] != player) diag2Win = false;
    }
    return diag1Win || diag2Win;
}

// Function to check if the board is full (draw condition)
bool isBoardFull(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    char currentPlayer = 'X';
    int row, col;
    bool gameWon = false;

    // Game loop
    while (!gameWon && !isBoardFull(board)) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (makeMove(board, row - 1, col - 1, currentPlayer)) {
            // Check if the current player wins
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameWon = true;
            } else {
                // Switch player after a valid move
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }

    if (!gameWon && isBoardFull(board)) {
        displayBoard(board);
        cout << "It's a draw!" << endl;
    }

    return 0;
}

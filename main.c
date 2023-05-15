#include <stdio.h>

char board[3][3]; // Game board

// Initialize the game board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Display the current game board
void displayBoard() {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

// Check if a player has won
int checkWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (boagird[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

// Play the game
void playGame() {
    char currentPlayer = 'X';
    int row, col;
    int moves = 0;

    initializeBoard();
    displayBoard();

    // Game loop
    while (1) {
        printf("Player %c's turn. Enter row (0-2) and column (0-2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Validate input
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Update the game board
        board[row][col] = currentPlayer;
        moves++;
        displayBoard();

        // Check for a win or draw
        if (checkWin(currentPlayer)) {
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        if (moves == 9) {
            printf("It's a draw!\n");
            break;
        }

        // Switch to the next player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    printf("Welcome to Tic-Tac-Toe!\n");
    playGame();
    return 0;
}

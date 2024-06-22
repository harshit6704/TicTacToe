#include <stdio.h>
void printBoard(char board[9]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i * 3 + j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
}
int checkWinner(char board[9]) {
    for (int i = 0; i < 3; i++) {
        if ((board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2]) && board[i * 3] != ' ')
            return board[i * 3];
        if ((board[i] == board[i + 3] && board[i + 3] == board[i + 6]) && board[i] != ' ')
            return board[i];
    }
    if ((board[0] == board[4] && board[4] == board[8]) && board[0] != ' ')
        return board[0];
    if ((board[2] == board[4] && board[4] == board[6]) && board[2] != ' ')
        return board[2];
    return 0;
}
int main() {
    char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char player = 'X';
    int moves = 0;
    int position;
    char winner = 0;
    while (moves < 9 && !winner) {
        printBoard(board);
        printf("Player %c, enter your move (position 0-8): ", player);
        scanf("%d", &position);        
        if (position >= 0 && position < 9 && board[position] == ' ') {
            board[position] = player;
            moves++;
            winner = checkWinner(board);
            player = (player == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
    printBoard(board);
    if (winner) {
        printf("Player %c wins!\n", winner);
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}
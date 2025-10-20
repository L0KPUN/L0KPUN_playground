#include <stdio.h>
#include <string.h>

//🔴
//🔵
//💣
//🕤🕘🕒🕞

int turn = 1; //starts with the first turn
int input = 0;

int last_row = 0;
int last_column = 0;

#define rows 6
#define columns 7

char bord[rows][columns];

int check_win(char player) {
    int count;

    // Horizontal
    count = 1;
    for (int c = last_column - 1; c >= 0 && bord[last_row][c] == player; c--) count++;
    for (int c = last_column + 1; c < columns && bord[last_row][c] == player; c++) count++;
    if (count >= 4) return 1;

    // Vertical
    count = 1;
    for (int r = last_row + 1; r < rows && bord[r][last_column] == player; r++) count++;
    if (count >= 4) return 1;

    // Diagonal ↘
    count = 1;
    for (int r = last_row - 1, c = last_column - 1; r >= 0 && c >= 0 && bord[r][c] == player; r--, c--) count++;
    for (int r = last_row + 1, c = last_column + 1; r < rows && c < columns && bord[r][c] == player; r++, c++) count++;
    if (count >= 4) return 1;

    // Diagonal ↗
    count = 1;
    for (int r = last_row + 1, c = last_column - 1; r < rows && c >= 0 && bord[r][c] == player; r++, c--) count++;
    for (int r = last_row - 1, c = last_column + 1; r >= 0 && c < columns && bord[r][c] == player; r--, c++) count++;
    if (count >= 4) return 1;

    return 0;
}




void print_bord()
{
    printf("\n");
    for (int row = 0; row < rows; row++){
        for (int column = 0; column < columns; column++) {
            printf("| %c ", bord[row][column]);
        }
        printf("|\n");
    }
    printf("  1   2   3   4   5   6   7  ");
}




void place(int column,char c)
{
    int row = rows - 1;
    while (1){
        if (bord[row][column] == ' '){
            break;
        }
        row--;
    }
    bord[row][column] = c;
    last_row = row;
    last_column = column;
}




void paragraph(int amount)
{
    for (int count = 0 ; count < amount ; count++){
        printf("\n");
    }
}




void main()
{   
    while(1)
    {
        memset(bord, ' ', sizeof(bord));
        while (1)
        {
            print_bord();
            paragraph(2);
            printf("Turn: %d\n",turn);

            if (turn % 2 != 0) { // Player 1
                while (1){
                    printf("Player 1: ");
                    scanf("%d", &input);
                    if ((input < 8 && input > 0) && bord[0][input - 1] == ' '){
                        break;
                    }
                }
                place(input - 1, 'X');
                if (turn > 5 && check_win('X')) {
                    print_bord();
                    printf("\n\nPlayer 1 wins!\n\n");
                    break;
                }
            } else { // Player 2
                while (1){
                    printf("Player 1: ");
                    scanf("%d", &input);
                    if (input < 8 && input > 0){
                        break;
                    }
                }
                place(input - 1, 'O');
                if (turn > 6 && check_win('O')) {
                    print_bord();
                    printf("\n\nPlayer 2 wins!\n\n");
                    break;
                }
            }
            paragraph(2);
            turn++;
        }
    }
}
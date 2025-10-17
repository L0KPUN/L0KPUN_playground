#include <stdio.h>
#include <string.h>

//🔴
//🔵
//💣
//🕤🕘🕒🕞

int turn = 1; //starts with the first turn
int input = 0;

#define rows 6
#define columns 7

char bord[rows][columns];

void print_bord()
{
    printf("\n");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++) {
            printf("| %c ", bord[i][j]);
        }
        printf("|\n");
    }
    printf("  1   2   3   4   5   6   7  ");
}

void place(int column,char c)
{
    int row = rows;
    while (1){
        if (bord[row][column] == ' '){
            break;
        }
        row--;
    }
    bord[row][column] = c;
}

void paragraph(int count)
{
    for (int i = 0 ; i < count ; i++){
        printf("\n");
    }
}

void main()
{   
    memset(bord, ' ', sizeof(bord));
    while (turn < rows * columns + 2)
    {
        print_bord();
        paragraph(2);

        printf("Turn: %d\n",turn);

        if (turn % 2 != 0){ //player1
            printf("Payer 1: ");
            scanf("%d",&input);
            place(input-1,'X');
        } else { //player 2
            printf("Payer 2: ");
            scanf("%d",&input);
            place(input-1,'O');
        }

        paragraph(2);
        turn++;
    }
}
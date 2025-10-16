#include <stdio.h>

//📀
//💿

int i = 0;

int turn = 0;
int with = 9;
int hight = 7;
int input = 0;

#define ZEILEN 6
#define SPALTEN 7

char bord[ZEILEN][SPALTEN] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '}
};

void print_bord()
{
    printf("\n");
    for (int i = 0; i < ZEILEN; i++) {
        for (int j = 0; j < SPALTEN; j++) {
            printf("| %c ", bord[i][j]);
        }
        printf("|\n");
    }
    printf("  1   2   3   4   5   6   7  ");
}

void place(int a,int b,int c)
{
    bord[a][b] = c;
}

void paragraph(int count)
{
    for (i = 0 ; i < count ; i++){
        printf("\n");
    }
}

void main()
{
    print_bord();
    paragraph(2);

    int turn =+ 1;
    printf("Turn: %d\n",turn);

    if (turn % 2 != 0){ //player1
        printf("Payer 1: ");
        scanf("%ls",&input);
    } else { //player 2

    }

    paragraph(2);
}
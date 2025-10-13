#include <stdio.h>
 
 /**
    The the grid is just like the number pad 
        7 8 9
        4 5 6
        1 2 3
    press the numbers to place a tile
    to play again press 0
*/

int main (void)
{
    int turn = 1; //starts with the first turn 1
    int i = 0;
    int j = 0;
    int imput = 0;
    int winner = 0;
    int again = 0;
    int bord[9] = {0,0,0, 0,0,0, 0,0,0};

    while (again < 1){
        //reset bord
        for (i = 6 ; i > -1 ; i = i-3){
                for (j = 0 ; j < 3 ; j++){
                    bord[i+j] = 0;
                }
            }

        //start game
        while (turn < 10){
            //display bord
            for (i = 6 ; i > -1 ; i = i-3){
                for (j = 0 ; j < 3 ; j++){
                    printf("%d ",bord[i + j]);
                }
                printf("\n");
            }

            //players turn
            if (turn % 2 == 0){ //every second turn is player 2 
                //player 2
                printf("\nPlayer 2: ");
                i = 0;
                while (i < 1){
                    scanf("%d",&imput);
                    if (imput > 0 && imput < 10 && bord[imput-1] == 0){
                        bord[imput-1] = 2;
                        printf("\n");
                        i = 1;
                    } else {
                        printf("again: ");
                    }
                }
            } else { //starting with th first every second turn is player 1
                //player 1
                printf("\nPlayer 1: ");
                i = 0;
                while (i < 1){
                    scanf("%d",&imput);
                    if (imput > 0 && imput < 10 && bord[imput-1] == 0){
                        bord[imput-1] = 1;
                        printf("\n");
                        i = 1;
                    } else {
                        printf("again: ");
                    }
                }
            }

            //check for win
            //check horizontal
            for (i = 6 ; i > -1 ; i = i-3){
            if (bord[i] == bord[i+1] && bord[i+1] == bord[i+2] && bord[i] != 0){
                turn = 100;
                winner = bord[i];
            }
            }
            //check vertikal
            for (i = 0 ; i < 3 ; i++){
            if (bord[i] == bord[i+3] && bord[i+3] == bord[i+6] && bord[i] != 0){
                turn = 100;
                winner = bord[i];
            }
            }
            //check diagonal
            if (bord[4] == bord[2] && bord[2] == bord[6] && bord[4] != 0 || bord[4] == bord[0] && bord[0] == bord[8] && bord[4] != 0){
                turn = 100;
                winner = bord[4];
            }

            //next turn
            turn++;
        }

        //display winner
        printf("The Winner is Player %d\n",winner);

        //display final bord
        for (i = 6 ; i > -1 ; i = i-3){
            for (j = 0 ; j < 3 ; j++){
                printf("%d ",bord[i + j]);
            }
            printf("\n");
        }

        //check if the players want to play again
        printf("\nPlay again? ");
        scanf("%d",&imput);
        if (imput != 0){
            printf("\n");
            return 0;
        } else {
            printf("\n");
            again = 0;
            turn = 1;
        }
    }
}
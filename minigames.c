#include <stdio.h>
#include <string.h>

int selected_game = 0;

int tick_tack_toe()
{
    int turn = 1; //starts with the first turn 1
    int i = 0;
    int j = 0;
    int imput = 0;
    int winner = 0;
    int again = 0;
    int bord[9] = {0,0,0, 0,0,0, 0,0,0};

    //set bord
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
    if (winner == 0){
        printf("There is no Winner\n");
    } else {
        printf("The Winner is Player %d\n",winner);
    }

    //display final bord
    for (i = 6 ; i > -1 ; i = i-3){
        for (j = 0 ; j < 3 ; j++){
            printf("%d ",bord[i + j]);
        }
        printf("\n");
    }
}

int connect_four()
{
    int turn = 1; //starts with the first turn
    int input = 0;

    int last_row = 0;
    int last_column = 0;

    #define rows 6
    #define columns 7

    char bord[rows][columns];

    int check_win(char player)
    {
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

int main()
{
    while (1)
    {
        printf("tick_tack_toe  ;  connect_four\n");
        printf("      1        ;        2\n\n\n");
        scanf("%d",&selected_game);
        
        if (selected_game == 0){
            break;
        } else if (selected_game == 1){
            printf("\n");
            tick_tack_toe();
        } else if (selected_game == 2){
            printf("\n");
            connect_four();
        }
        
        printf("\n\n\n");
    }
}

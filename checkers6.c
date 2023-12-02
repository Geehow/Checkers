/*
    Jiahao Yuan
    COP3223
    Assignment 6

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "checkers.h"

// global constants a.k.a. macros
//#define NAME 20
//#define PLAYER_B 1
//#define PLAYER_W 2
//#define ZERO 0
//#define FOUR 4
//#define ROW 8
//#define COL 8
//#define TWO 2
//#define THREE 3
//#define SPACE ' '
//#define TRUE 1
//#define FALSE 0
//#define INVALID -1

//struct
//struct Player {
//    int playerNum;
//    char playerName[20];
//    int numCheckers;
//    char playerChar;
//};

// function prototypes
//void welcomeScreen ();
//void displayExplicitBoard();
//void clearScreen();
//void playGame();
//void initializeBoard(char board[ROW][COL]);
//void displayBoard(char board[ROW][COL]);
//void makeMove(struct Player *player, char board[ROW][COL]);
//int isValid (char start[THREE], char end[THREE],char board[ROW][COL], char playerChar);
//int isOpen(char end[THREE], char board[ROW][COL]);
//int hasChecker(char start[THREE],char board[ROW][COL],char playerChar);
//int getMoveRow(char move[THREE]);
//int getMoveCol(char move[THREE]);
//void displayStats(struct Player player);
//int isDiagonal(char start[THREE], char end[THREE], char playerChar);
//void updateBoard(char start[THREE], char end[THREE], char board[ROW][COL]);
//void updateCheckerCount(char board[ROW][COL], struct Player *player);

// main function
int main()
{
    // call function welcomeScreen
    welcomeScreen();
    // call function clearScreen
    clearScreen();
    // call function displayExplicitBoard
//    displayExplicitBoard();
    // call function playGame
    playGame();
    // program executed successfully
    return 0;
}

// welcomeScreen function displays the Checkers logo and rules of the game
void welcomeScreen ()
{
	printf ("\t\t CCCC  HH  HH  EEEEE   CCCC  KK  KK  EEEEE  RRRRR    SSSS   \n");
	printf ("\t\tCC     HH  HH  EE     CC     KK KK   EE     RR RR   SS      \n");
	printf ("\t\tCC     HHHHHH  EEEE   CC     KKK     EEEE   RRRR     SSSS   \n");
	printf ("\t\tCC     HH  HH  EE     CC     KK KK   EE     RR RR       SS  \n");
	printf ("\t\t CCCC  HH  HH  EEEEE   CCCC  KK  KK  EEEEE  RR  RR  SSSSS   \n");
	printf ("\n\n");
	printf ("CHECKERS GAME RULES\n\n");
    printf("\t 1. The board includes 64 alternating dark and light squares with 8 rows and 8 columns.\n");
    printf("\t 2. Each player places their pieces on the 12 dark squares in the first 3 rows closest to them.\n");
    printf("\t 3. Each of these 3 rows should have a total of 4 checkers.\n");
    printf("\t 4. The player with the black checkers always goes first.\n");
    printf("\t 5. Players can only move 1 checker 1 diagonal space forward during a regular turn.\n");
    printf("\t 6. Checkers must stay on the dark squares.\n");
    printf("\t 7. Jump the opponent's checkers to remove them from the board.\n");
    printf("\t 8. Players alternate turns.\n");
    printf("\t 9. If a player can jump their opponent's checker, the player must jump it.\n");
    printf("\t10. A player must keep capturing their opponent's checkers until no checkers are available to jump.\n");
    printf("\t11. Players king their pieces when their checkers reach the end of their opponent's side.\n");
    printf("\t12. The king can move forward and backward diagonally on the dark squares.\n");
    printf("\t13. Once a player has captured all their opponent's checkers, they have won the game!\n");
}

// function displayExplicitBoard displays a hardcoded version of an Checkers board
void displayExplicitBoard()
{
    printf("|-----------------------------------------------------|\n");
    printf("|     |  A  |  B  |  C  |  D  |  E  |  F  |  G  |  H  |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  1  |     |  W  |     |  W  |     |  W  |     |  W  |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  2  |  W  |     |  W  |     |  W  |     |  W  |     |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  3  |     |  W  |     |  W  |     |  W  |     |  W  |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  4  |     |     |     |     |     |     |     |     |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  5  |     |     |     |     |     |     |     |     |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  6  |  B  |     |  B  |     |  B  |     |  B  |     |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  7  |     |  B  |     |  B  |     |  B  |     |  B  |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  8  |  B  |     |  B  |     |  B  |     |  B  |     |\n");
    printf("|-----------------------------------------------------|\n");
 }

// function clearScreen clears the screen for display purposes
void clearScreen()
{
    printf("\n\t\t\t\tHit <ENTER> to continue!\n");

	char enter;
	scanf("%c", &enter );

	// send the clear screen command Windows
    system("cls");
    // send the clear screen command for UNIX flavor operating systems
//    system("clear");
}

void playGame()
{
    // get player names
    struct Player playerB;  // Karin 
    struct Player playerW;  // Lia

    // black (B) always goes first
    int currentPlayer = PLAYER_B;
    int loop = ZERO;

    char board[ROW][COL]; // this is really a memory location of board[0][0]

    // black (X) always goes first
    printf("Player B, please enter your name\n");
    scanf("%s", playerB.playerName);
    // setting the value of the struct fields for playerB
    playerB.playerNum = PLAYER_B;
    playerB.numCheckers= 12;
    playerB.playerChar = 'B';

    printf("Player W, please enter your name\n");
    scanf("%s", playerW.playerName);
    // setting the value of the struct fields for playerW
    playerW.playerNum = PLAYER_W;
    playerW.numCheckers = 12;
    playerW.playerChar = 'W';

    printf("%s and %s, let's play Checkers!\n", playerB.playerName, playerW.playerName);

    // call function initializeBoard
    initializeBoard(board);

    while(gameOver(playerB, playerW) == FALSE)
    {
        displayBoard(board);
        // switch players for each move
        if(currentPlayer == PLAYER_B)
        {
            makeMove(&playerB, board);
            // showing both player's stats
            updateCheckerCount(board, &playerB);
            updateCheckerCount(board, &playerW);
            displayStats(playerB);
            displayStats(playerW);
            currentPlayer = PLAYER_W;
        }
        else if(currentPlayer == PLAYER_W)
        {
            makeMove(&playerW, board);
            // showing both player's stats
            updateCheckerCount(board, &playerB);
            updateCheckerCount(board, &playerW);
            displayStats(playerB);
            displayStats(playerW);
            currentPlayer = PLAYER_B;
        }

        //loop++;
        //setEndGame(&playerW);
    }
    displayWinner(&playerB, &playerW);
}

void initializeBoard(char board[ROW][COL])
{
    int row;
    for(row = 0; row < ROW; row++)
    {
        int col;
        for(col = 0; col < COL; col++)
        {
            if(row < 3)
            {
                if(row % 2 == 0 && col % 2 == 0)
                    board[row][col] = SPACE;
                else if(row % 2 != 0 && col % 2 != 0)
                    board[row][col] = SPACE;
                else
                    board[row][col] = 'W';
            }
            else if (row > 4)
            {
                if(row % 2 == 0 && col % 2 == 0)
                    board[row][col] = SPACE;
                else if(row % 2 != 0 && col % 2 != 0)
                    board[row][col] = SPACE;
                else
                    board[row][col] = 'B';
            }
            else
            {
                board[row][col] = SPACE;
            }
        }
    }
}

void displayBoard(char board[ROW][COL])
{
    int row;
    printf("|-----------------------------------------------------|\n");
    printf("|     |  A  |  B  |  C  |  D  |  E  |  F  |  G  |  H  |\n");

    for(row = 0; row < ROW; row++)
    {
        printf("|-----------------------------------------------------|\n");
        printf("|  %d  |", (row + 1));

        int col;
        for(col = 0; col < COL; col++)
        {
            printf("  %c  |", board[row][col]);
        }

        printf("\n");
    }

    printf("|-----------------------------------------------------|\n");
}

void makeMove(struct Player *player, char board[ROW][COL])
{
    char start[THREE];
    char end[THREE];
    int valid = FALSE;

    // loop until the player enters a valid move
    while(valid == FALSE)
    {
        printf("%s, enter location of checker to move (e.g. B6)\n", player->playerName);
        scanf("%s", start);
        printf("%s, you entered %s\n", player->playerName, start);

        int length = (int)strlen(start);
        // checking if move is 2 characters
        if(length == TWO){
            printf("%s, enter new location of checker to move (e.g. C5)\n", player->playerName);
            scanf("%s", end);

            printf("%s, you entered checker %s to square %s\n", player->playerName, start, end);

            int lengthE = (int)strlen(end);
            // checking if end is 2 characters and isValid is returning TRUE
            if((length == TWO) && (lengthE == TWO) && (isValid(start, end, board, player->playerChar) == TRUE)){
                valid = TRUE;

                updateBoard(start, end, board);

                printf("\tSelected Checker is valid!\n");               
                printf("\tSelected move is valid!\n");
                printf("\tEnd position is open!\n");
            }
            else{
                valid = FALSE;
            }
        }
        else{
            valid = FALSE;
        }

        if(valid == FALSE){
            printf("\tInvalid move, try again\n\n");
        }
    }
}

//function isValid
int isValid (char start[THREE], char end[THREE],char board[ROW][COL], char playerChar){
    int valid = FALSE;
    // updating valid with TRUE or FALSE based on hasChecker Function
    valid = hasChecker(start, board, playerChar);
 
    if (valid == FALSE){
        return valid;
    }
    // updating valid with TRUE or FALSE based on isOpen Function
    valid = isOpen(end, board);
    if (valid == FALSE){
        return valid;
    }
    valid = isDiagonal(start, end, playerChar, board);
    if (valid == FALSE){
        return valid;
    }
    return valid;
}
//function isOpen
int isOpen(char end[THREE], char board[ROW][COL]){
    int open = FALSE;
    // gets the indexes for the board row and column to check the array
    int rowInt = getMoveRow(end);
    int colInt = getMoveCol(end);
    // checking if the row and col are valid and if the position on the board is a space
    if (rowInt != INVALID && colInt != INVALID && board[rowInt][colInt] == SPACE){
        open = TRUE;
        
    }
    else{
        open = FALSE;
    }
    return open;
}
//function hasChecker
int hasChecker(char start[THREE],char board[ROW][COL],char playerChar){
    int checker = FALSE;
    // grabbing the row and col from start
    int rowInt = getMoveRow(start);
    int colInt = getMoveCol(start);
    // checking if the row and col are valid and if the position on the board is their piece.
    if (rowInt != INVALID && colInt != INVALID && board[rowInt][colInt] == playerChar){
        checker = TRUE;
    }
    else {
        checker = FALSE;
    }
    return checker;
}
//function getMoveRow
int getMoveRow(char move[THREE]){
    //grabs move[1] and subtracts 1 from them to match the correct index on the board array
    switch(move[1]){
        case '1':
            return 0;
        case '2':
            return 1;
        case '3':
            return 2;
        case '4':
            return 3;
        case '5':
            return 4;
        case '6':
            return 5;
        case '7':
            return 6;
        case '8':
            return 7;
        // if the user does not input 1-8, then it returns invalid.
        default:
            return INVALID;
    }
}

//function getMoveCol
int getMoveCol(char move[THREE]){
    // makes sure move[0] is capitalized
    move[0] = toupper(move[0]);
    switch (move[0]) {
        // A returns 0 since we start at 0 and so on.
        case 'A':
            return 0;
        case 'B':
            return 1;
        case 'C':
            return 2;
        case 'D':
            return 3;
        case 'E':
            return 4;
        case 'F':
            return 5;
        case 'G':
            return 6;
        case 'H':
            return 7;
        // // if the user does not input A - H , then it returns invalid.
        default:
            return INVALID;
    }
}

//function displayStats
void displayStats(struct Player player){
    //printf statements displaying each field of the struct Player
    printf("Player name:      %s\n", player.playerName);
    printf("Player number:    %d\n", player.playerNum);
    printf("Player character: %c\n", player.playerChar);
    printf("Player checkers:  %d\n\n", player.numCheckers);
}

//function isDiagonal
int isDiagonal(char start[THREE], char end[THREE], char playerChar, char board[ROW][COL]){
    int diagonal = FALSE;
    // getting the starting and ending row and col
    int sRow = getMoveRow(start);
    int sCol = getMoveCol(start);
    int eRow = getMoveRow(end);
    int eCol = getMoveCol(end);
    // checking if W is moving down and diagonally and if B is moving up and diagonally.
    if (sRow != INVALID && sCol != INVALID && eRow != INVALID && eCol != INVALID && 
    (playerChar == 'W' && (eRow == sRow + 1) && (eCol == sCol +1 || eCol == sCol - 1)) 
    || (playerChar == 'B' && (eRow == sRow - 1) && (eCol == sCol + 1 || eCol == sCol - 1))){
        diagonal = TRUE;
    }
    else if(isJump(sRow, sCol, eRow, eCol, board, playerChar) == TRUE){
        diagonal = TRUE;
    }
    return diagonal;
}

//function updateBoard
void updateBoard(char start[THREE], char end[THREE], char board[ROW][COL]){
    // getting the starting and ending rows and cols
    int sRow = getMoveRow(start);
    int sCol = getMoveCol(start);
    int eRow = getMoveRow(end);
    int eCol = getMoveCol(end);

    int isJump = abs(sRow - eRow) == 2 || abs (sCol - eCol) == 2;

    //swapping the space with the playerchar
    board[eRow][eCol] = board[sRow][sCol];
    board[sRow][sCol] = SPACE;

    if (isJump){
        int jumpedRow = (sRow + eRow) / 2;
        int jumpedCol = (sCol + eCol) / 2;
        board[jumpedRow][jumpedCol] = SPACE;
    }
}

//function updateCheckerCount
void updateCheckerCount(char board[ROW][COL], struct Player *player){
    int count = 0;
    int row;
    int col;
    //iterating through the rows and cols to count how many player checkers there are on the board.
     for(row = 0; row < ROW; row++)
    {
        for(col = 0; col < COL; col++)
        {
            if (board[row][col] == player->playerChar) {
                count++;
            }
        }
    }
    player->numCheckers = count;
}

int isJump(int sRow, int sCol, int eRow, int eCol, char board[ROW][COL], char playerChar){
    int jump = FALSE;
    int rowDiff = eRow - sRow;
    int colDiff = eCol - sCol;
    int colInt = INVALID;
    int rowInt = INVALID;
    // checking if B is moving up 2 and to the left or right 2
    if (playerChar == 'B' && rowDiff == -2 && (colDiff == 2 || colDiff == -2)){
        rowInt = sRow + (rowDiff/2);
        colInt = sCol + (colDiff/2);
        if (board[rowInt][colInt] != playerChar && board[rowInt][colInt] != SPACE) {
            jump = TRUE;
        }
    }
    //checking if W is moving down 2 and to the left or right 2
    else if (playerChar == 'W' && rowDiff == 2 && (colDiff == 2 || colDiff == -2)){
        rowInt = sRow + (rowDiff/2);
        colInt = sCol + (colDiff/2);
        if (board[rowInt][colInt] != playerChar && board[rowInt][colInt] != SPACE) {
            jump = TRUE;
        }

    }
    return jump;
}

int gameOver(struct Player playerB, struct Player playerW){
    //returns true is either playerB or playerW checker count is 0
    if ((playerB.numCheckers == 0) || (playerW.numCheckers == 0)){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void displayWinner (struct Player *playerB, struct Player *playerW){
    //if player B checker count is 0, player W wins
    if (playerB->numCheckers == 0){
        printf("%s has won the game!\n", playerW->playerName);
        displayStats(*playerB);
        displayStats(*playerW);
    }
    //if player W checker count is 0, playerB wins
    else if(playerW->numCheckers == 0){
        printf("%s has won the game!\n", playerB->playerName);
        displayStats(*playerB);
        displayStats(*playerW);
    }
}

void setEndGame (struct Player *player){
    //setting the player's checker count to 0
    player->numCheckers = 0;
}

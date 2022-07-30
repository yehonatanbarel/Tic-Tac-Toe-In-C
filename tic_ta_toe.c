#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// I CHANGED THE VAR 'playerTurn' FROM CHAR TO STRING WITH SIZE 1 SO AFTER THAT I COULD USE THE
// METHOED FROM <STRING.H> STRCPY TO CHANGE THE VALUE. BECAUSE I CANT CHANGE THE VALUE
// OF A CHAR INSIDE THE FUNC (BY VALUE \ BY REFFERNCE).
// BUT WITH THE STRING METHOD I COULD CHANGE.
// MAYBE I COULD HAVE CHANGE IF I WAS USING POINTERS, NEED TO CHECK THIS.

// TO-DO: CHECK HOW TO CHANGE THE BOOL TYPE FOR GAME OVER, SAME PROBLAME AS ABOVE

void checkForWin(char board[3][3], bool *isGameOver);
void drawBoard(char board[3][3]);
void switchTurn(char playerTurn[1]);
void updateBoard(char board[3][3], char playerTurn, int squareToChange);

int main()
{
    bool isGameOver = false;
    char playerTurn[1] = "X";
    int squareToChange = 0;

    printf("\tTIC-TA-TOE GAME\n");
    printf("Player_1 is: O\nPlayer_2 is: X\n");
    // char is beeter than int because then i could change the char to 'X' / 'O'
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};

    printf("\n");
    // print the board
    drawBoard(board);

    do
    {
        // drawBoard(board);
        printf("Player %c turn, your square choice is: ", playerTurn[0]);
        scanf("%d", &squareToChange);
        updateBoard(board, playerTurn[0], squareToChange);
        checkForWin(board, &isGameOver);
        switchTurn(playerTurn);
    } while (!isGameOver);

    return 0;
}

// ================ FUNC ================

bool isValidInput(int squareToChange)
{
    switch (squareToChange)
    {
    case 1:
        return true;
        break;
    case 2:
        return true;
        break;
    case 3:
        return true;
        break;
    case 4:
        return true;
        break;
    case 5:
        return true;
        break;
    case 6:
        return true;
        break;
    case 7:
        return true;
        break;
    case 8:
        return true;
        break;
    case 9:
        return true;
        break;
    default:
        return false;
        break;
    }
}

void switchTurn(char playerTurn[1])
{
    if (playerTurn[0] == 'X')
    {
        strcpy(playerTurn, "O");
        // playerTurn = 'O';
    }
    else if (playerTurn[0] == 'O')
    {
        strcpy(playerTurn, "X");
        // playerTurn = 'X';
    }
}

void updateBoard(char board[3][3], char playerTurn, int squareToChange)
{

    switch (squareToChange)
    {
    case (0):
        break;

    case (1):
        board[0][0] = playerTurn;
        drawBoard(board);
        break;
    case (2):
        board[0][1] = playerTurn;
        drawBoard(board);
        break;
    case (3):
        board[0][2] = playerTurn;
        drawBoard(board);
        break;
    case (4):
        board[1][0] = playerTurn;
        drawBoard(board);
        break;
    case (5):
        board[1][1] = playerTurn;
        drawBoard(board);
        break;
    case (6):
        board[1][2] = playerTurn;
        drawBoard(board);
        break;
    case (7):
        board[2][0] = playerTurn;
        drawBoard(board);
        break;
    case (8):
        board[2][1] = playerTurn;
        drawBoard(board);
        break;
    case (9):
        board[2][2] = playerTurn;
        drawBoard(board);
        break;
    }
}

void drawBoard(char board[3][3])
{
    printf("The Board\n %c | %c | %c\n-----------\n %c | %c | %c\n-----------\n %c | %c | %c\n",
           board[0][0], board[0][1], board[0][2],
           board[1][0], board[1][1], board[1][2],
           board[2][0], board[2][1], board[2][2]);
}

// i change here that the input this func gets it's the pointer to the var of 'isGameOver'
// and then inside the func i change the value of what is inside that memory place
void checkForWin(char board[3][3], bool *isGameOver)
{

    // winner on row
    if (board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][1] == board[0][2])
    {
        printf("The winner is: %c\n", board[0][0]);
        *isGameOver = true;
    }
    else if (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][1] == board[1][2])
    {
        printf("The winner is: %c\n", board[1][0]);
        *isGameOver = true;
    }
    else if (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][1] == board[2][2])
    {
        printf("The winner is: %c\n", board[2][0]);
        *isGameOver = true;

        // winner on col
    }
    else if (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[1][0] == board[2][0])
    {
        printf("The winner is: %c\n", board[0][0]);
        *isGameOver = true;
    }
    else if (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[1][1] == board[2][1])
    {
        printf("The winner is: %c\n", board[0][1]);
        *isGameOver = true;
    }
    else if (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[1][2] == board[2][2])
    {
        printf("The winner is: %c\n", board[0][2]);
        *isGameOver = true;

        // winner on diag
    }
    else if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[1][1] == board[2][2])
    {
        printf("The winner is: %c\n", board[0][0]);
        *isGameOver = true;
    }
    else if (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[1][1] == board[0][2])
    {
        printf("The winner is: %c\n", board[2][0]);
        *isGameOver = true;
    }
    // else
    // {
    //     // if it's not gameOver
    //     // switch player turn

    //     printf("It's %c turn", playerTurn);
    // }
}

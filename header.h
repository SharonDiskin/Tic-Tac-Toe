#include <iostream>
using namespace std;

const int SIZE = 3;

const int  NO_PLAYER = 0;
const char PLAYER_1_SIGN = 'X';
const char PLAYER_2_SIGN = 'O';

const int GAME_STATUS_WINNER_PLAYER_1 = 1;
const int GAME_STATUS_WINNER_PLAYER_2 = 2;
const int GAME_STATUS_TIE = 3;
const int GAME_STATUS_NO_RESULT_YET = 0;

int playGame();
void drawBoard(char board[][SIZE]);
int checkGameStatus(char board[][SIZE]);
int checkIfWinnerInRow(char board[][SIZE]);
int checkIfWinnerInCol(char board[][SIZE]);
int checkIfWinnerInMainDiagonal(char board[][SIZE]);
int checkIfWinnerInSecondaryDiagonal(char board[][SIZE]);
int checkIfNotAllCellsTaken(char board[][SIZE]);

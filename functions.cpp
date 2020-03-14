
int playGame()
{
	char board[SIZE][SIZE] = { NO_PLAYER };
	int  currentPlayer = 1;
	bool fIsCellFree, fHasWinner = false;
	int row, col, res;

	do
	{
		system("cls");

		cout << "The current board:\n\n";
		drawBoard(board);
		cout << "\n";

		fIsCellFree = false;
		while (!fIsCellFree)
		{
			cout << "Please enter cordination for player #" << currentPlayer << ": ";
			cin >> row >> col;

			if (row<1 || row > SIZE || col <1 || col>SIZE) {
				cout << "The cordinations must be between 1 to " << SIZE << endl;
				system("pause");
				continue;
			}

			if (board[row - 1][col - 1] != NO_PLAYER)
			{
				cout << "The cell is already taken!\n";
				system("pause");
				continue;
			}

			// if here, cell is valid...
			//-----------------------------

			//  mark cell and switch player
			fIsCellFree = true;
			if (currentPlayer == 1)
			{
				board[row - 1][col - 1] = PLAYER_1_SIGN;
				currentPlayer = 2;
			}
			else
			{
				board[row - 1][col - 1] = PLAYER_2_SIGN;
				currentPlayer = 1;
			}
		}
		system("pause");
	} while (checkGameStatus(board) == GAME_STATUS_NO_RESULT_YET);


	cout << "Final Board:\n";
	drawBoard(board);

	res = checkGameStatus(board);
	return res;
}

int checkGameStatus(char board[][SIZE])
{

	int res;

	res = checkIfWinnerInRow(board);
	if (res == GAME_STATUS_WINNER_PLAYER_1 || res == GAME_STATUS_WINNER_PLAYER_2)
		return res;

	res = checkIfWinnerInCol(board);
	if (res == GAME_STATUS_WINNER_PLAYER_1 || res == GAME_STATUS_WINNER_PLAYER_2)
		return res;

	res = checkIfWinnerInMainDiagonal(board);
	if (res == GAME_STATUS_WINNER_PLAYER_1 || res == GAME_STATUS_WINNER_PLAYER_2)
		return res;

	res = checkIfWinnerInSecondaryDiagonal(board);
	if (res == GAME_STATUS_WINNER_PLAYER_1 || res == GAME_STATUS_WINNER_PLAYER_2)
		return res;

	res = checkIfNotAllCellsTaken(board);
	if (res == GAME_STATUS_NO_RESULT_YET)
		return res;

	// if we haven't returned yet, then there is no winner and the board is full, therefore TIE
	return GAME_STATUS_TIE;
}

void drawBoard(char board[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << " ";
			if (board[i][j] != NO_PLAYER)
				cout << board[i][j];
			else
				cout << " ";
			cout << " |";
		}
		cout << "\n";
		for (int j = 0; j < SIZE; j++)
			cout << "---|";
		cout << "\n";
	}
}

int checkIfWinnerInRow(char board[][SIZE])
{
	bool fHasWinnerInCurrentCheck;

	for (int i = 0; i < SIZE; i++)
	{
		fHasWinnerInCurrentCheck = true;
		for (int j = 1; j < SIZE && fHasWinnerInCurrentCheck; j++)
		{
			if (board[i][j] != board[i][0] || board[i][j] == NO_PLAYER)
				fHasWinnerInCurrentCheck = false;
		}

		if (fHasWinnerInCurrentCheck)
		{
			if (board[i][0] == PLAYER_1_SIGN)
				return GAME_STATUS_WINNER_PLAYER_1;
			else
				return GAME_STATUS_WINNER_PLAYER_2;
		}
	}
	return GAME_STATUS_NO_RESULT_YET;
}

int checkIfWinnerInCol(char board[][SIZE]) {
	bool fHasWinnerInCurrentCheck;

	for (int i = 0; i < SIZE; i++)
	{
		fHasWinnerInCurrentCheck = true;
		for (int j = 1; j < SIZE && fHasWinnerInCurrentCheck; j++)
		{
			if (board[j][i] != board[0][i] || board[j][i] == NO_PLAYER)
				fHasWinnerInCurrentCheck = false;
		}

		if (fHasWinnerInCurrentCheck)
		{
			if (board[0][i] == PLAYER_1_SIGN)
				return GAME_STATUS_WINNER_PLAYER_1;
			else
				return GAME_STATUS_WINNER_PLAYER_2;
		}
	}
	return GAME_STATUS_NO_RESULT_YET;
}

int checkIfWinnerInMainDiagonal(char board[][SIZE]) {

	bool fHasWinnerInCurrentCheck = true;
	for (int i = 0; i < SIZE && fHasWinnerInCurrentCheck; i++)
	{
		if (board[i][i] != board[0][0] || board[i][i] == NO_PLAYER)
			fHasWinnerInCurrentCheck = false;
	}

	if (fHasWinnerInCurrentCheck)
	{
		if (board[0][0] == PLAYER_1_SIGN)
			return GAME_STATUS_WINNER_PLAYER_1;
		else
			return GAME_STATUS_WINNER_PLAYER_2;
	}
	return GAME_STATUS_NO_RESULT_YET;
}

int checkIfWinnerInSecondaryDiagonal(char board[][SIZE]) {
	bool fHasWinnerInCurrentCheck = true;

	for (int i = 0, j = SIZE - 1; i < SIZE && fHasWinnerInCurrentCheck; i++, j--)
	{
		if (board[i][j] != board[0][SIZE - 1] || board[i][j] == NO_PLAYER)
			fHasWinnerInCurrentCheck = false;
	}

	if (fHasWinnerInCurrentCheck)
	{
		if (board[0][SIZE - 1] == PLAYER_1_SIGN)
			return GAME_STATUS_WINNER_PLAYER_1;
		else
			return GAME_STATUS_WINNER_PLAYER_2;
	}
	return GAME_STATUS_NO_RESULT_YET;
}

int checkIfNotAllCellsTaken(char board[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == NO_PLAYER)
				return GAME_STATUS_NO_RESULT_YET;
		}
	}
	return GAME_STATUS_TIE;
}

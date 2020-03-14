int main()
{
	int res;
	bool fPlayAgain = true;
	char answer;

	do
	{
		res = playGame();

		if (res == GAME_STATUS_WINNER_PLAYER_1)
			cout << "Winner: player 1\n";
		else if (res == GAME_STATUS_WINNER_PLAYER_2)
			cout << "Winner: player 2\n";
		else
			cout << "TIE, no winner...\n";

		cout << "Would you like to play again (Y/N)? ";
		cin >> answer;
		while (answer != 'n' && answer != 'N' && answer != 'y' && answer != 'Y')
		{
			cout << "Invalid answer. Try again: ";
			cin >> answer;
		}
		if (answer == 'n' || answer == 'N')
			fPlayAgain = false;
	} while (fPlayAgain);
}

#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Player.h"
#include "Board.h"


int main(int, char *[])
{
	srand(time(NULL));

	Player player = Player();
	Board board = Board(player);

	char c = ' ';

	while (c != 'x' && !board.gameOver() )
	{
		system("cls");
		player.printScore();
		board.printBoard();

		std::cin >> c;

		Movement move;
		switch (c)
		{
		case 'W':
		case 'w': move = Movement::UP;
			break;
		case 'A':
		case 'a': move = Movement::LEFT;
			break;
		case 'S':
		case 's': move = Movement::DOWN;
			break;
		case 'D':
		case 'd': move = Movement::RIGHT;
			break;
		default:
			return 0;
		};

		if (board.checkMovement(player.position, move))
		{
			if (board.existCoin(player.position, move)) { player.updateScore(1); };
			board.movePlayer(player.position, move);
		};
					
	}

	return 0;
}
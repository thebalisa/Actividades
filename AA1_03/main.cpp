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
		case 'w': move = Movement::UP;
			break;
		case 's': move = Movement::DOWN;
			break;
		case 'a': move = Movement::LEFT;
			break;
		case 'd': move = Movement::RIGHT;
			break;
		case 'W': move = Movement::UP;
			break;
		case 'S': move = Movement::DOWN;
			break;
		case 'A': move = Movement::LEFT;
			break;
		case 'D': move = Movement::RIGHT;
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
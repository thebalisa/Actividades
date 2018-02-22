#include <ctime>
#include <string>
#include <iostream>

const int NUM_ROWS = 10;
const int NUM_COLUMNS = 20;

enum Movement { UP, DOWN, LEFT, RIGHT }; //1

int board[NUM_ROWS][NUM_COLUMNS]; //2

struct items
{
	int coins;
	int stone;
};


struct playerInfo //3
{
	int position;
	int score;
};

void initializeBoard(int &board)
{
	for (int i = 0; i < 60; i++)
	{
		rand();
	}
	for (int j = 0; j < 40; j++)
	{

	}
}

bool checkMovement(playerInfo player, Movement)
{
	switch (player.position)
	{
	case Movement::UP:
			if ()
	default:
		break;
	}
}
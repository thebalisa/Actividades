#pragma once

const int NUM_ROWS = 10;
const int NUM_COLUMNS = 10;

//1
enum class Movement { UP, DOWN, LEFT, RIGHT };

enum CharName { NONE, PLAYER, STONE, COIN };
char g_CharCode[4] = { ' ', '@', 'X','$' };

struct Board
{
	//2
	char board[NUM_ROWS][NUM_COLUMNS];

	Board(Player const &player) {
		InitializeBoard();
		setPlayer(player.position);
	}

	//4
	void InitializeBoard()
	{
		int countStones = 0, countCoins = 0;
		for (int i = 0; i < NUM_ROWS; i++) {
			for (int j = 0; j < NUM_COLUMNS; j++) {
				switch (GetRandomCell())
				{
				case NONE:
					board[i][j] = g_CharCode[CharName::NONE];
					break;
				case STONE:
					board[i][j] = (countStones < (NUM_ROWS*NUM_COLUMNS)*0.2) ? g_CharCode[CharName::STONE] : g_CharCode[CharName::NONE];
					countStones++;
					break;
				case COIN:
					board[i][j] = (countCoins < (NUM_ROWS*NUM_COLUMNS)*0.3) ? g_CharCode[CharName::COIN] : g_CharCode[CharName::NONE];
					countCoins++;
					break;
				default:
					board[i][j] = g_CharCode[CharName::NONE];
					break;
				}
			}
		}
	}

	CharName GetRandomCell()
	{
		int rnd = rand() % 100;
		if (rnd < 20) return CharName::STONE;
		else if (rnd < 50) return CharName::COIN;
		return CharName::NONE;
	}

	void setPlayer(Vec2 pos) {
		board[pos.x][pos.y] = g_CharCode[CharName::PLAYER];
	}


	//5 Una funci�n checkMovement que recibe dos par�metros : la posici�n del jugador en el tablero y el tipo de Movement 
	// que se desea hacer.Devuelve true si el movimiento es v�lido y false en caso contrario.
	bool checkMovement(Vec2 pos, Movement mov)
	{
		switch (mov)
		{
		case Movement::LEFT:
			return !(pos.y - 1 < 0 || board[pos.x][pos.y - 1] == g_CharCode[CharName::STONE]);
		case Movement::RIGHT:
			return !(pos.y + 1 > NUM_COLUMNS - 1 || board[pos.x][pos.y + 1] == g_CharCode[CharName::STONE]);
		case Movement::UP:
			return !(pos.x - 1 < 0 || board[pos.x - 1][pos.y] == g_CharCode[CharName::STONE]);
		case Movement::DOWN:
			return !(pos.x + 1 > NUM_ROWS - 1 || board[pos.x + 1][pos.y] == g_CharCode[CharName::STONE]);
		}
	}

	//11
	void printBoard() {
		for (int i = 0; i < NUM_ROWS; i++) {
			for (int j = 0; j < NUM_COLUMNS; j++) {
				std::cout << "[" << board[i][j] << "] ";
			}
			std::cout << std::endl;
		}
	}


	//8	Una funci�n existsCoin que devuelve true si hay una moneda en la siguiene casilla a la 
	//que deber�a moverse el jugador seg�n el tipo de Movement que se la pasa c�mo par�metro y false en caso contrario.
	bool existCoin(Vec2 pos, Movement mov) {
		switch (mov)
		{
		case Movement::LEFT:
			return (board[pos.x][pos.y - 1] == g_CharCode[CharName::COIN]);
		case Movement::RIGHT:
			return (board[pos.x][pos.y + 1] == g_CharCode[CharName::COIN]);
		case Movement::UP:
			return (board[pos.x - 1][pos.y] == g_CharCode[CharName::COIN]);
		case Movement::DOWN:
			return (board[pos.x + 1][pos.y] == g_CharCode[CharName::COIN]);
		}
	}


	//9 Una funci�n movePlayer que mueve al jugador a la siguiente casilla de d�nde se encuentra 
	//dependiendo del tipo de Movement  que se le pasa c�mo par�metro. 
	void movePlayer(Vec2 &pos_, Movement move)
	{
		Vec2 newPos = pos_;

		//calcular cual seria la nueva posicion
		switch (move)
		{
		case Movement::LEFT: newPos = { pos_.x, pos_.y - 1 };
							 break;
		case Movement::RIGHT: newPos = { pos_.x, pos_.y + 1 };
							  break;
		case Movement::UP: newPos = { pos_.x - 1, pos_.y };
						   break;
		case Movement::DOWN: newPos = { pos_.x + 1, pos_.y };
							 break;
		}

		board[pos_.x][pos_.y] = g_CharCode[CharName::NONE];
		board[newPos.x][newPos.y] = g_CharCode[CharName::PLAYER];
		pos_ = newPos;  //actualiza la posicion del jugador

	}

	//10  Una funci�n gameOver que verifica si en el tablero no quedan monedas
	bool gameOver() {
		int count{ 0 };
		for (int i = 1; i<NUM_ROWS; i++)
			for (int j = 1; j<NUM_COLUMNS; j++)
			{
				if (board[i][j] == g_CharCode[CharName::COIN]) count++;
			}
		return count == 0;
	};
};
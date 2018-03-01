#pragma once

struct Vec2
{
	int x;
	int y;
};

//3
struct Player
{
	Vec2 position;
	int score;

	Player() : position({ 0 , 0 }), score() {};
	Player(Vec2 pos) : position(pos), score(0) {};

	inline void printScore() {
		std::cout << "---- Score: " << score << " ----" << std::endl;
		std::cout << "X->" << position.x << " // Y->" << position.y << std::endl;
	}

	//6 
	inline void updateScore(int points) { score += points; }

	//7
	void setPos(Vec2 pos) {
		position = pos;
	}
};
#ifndef SNAKE_H
#define SNAKE_H
#include<windows.h>
#include "food.h"
#include<vector>
using namespace std;
class snake
{
	private:
		COORD pos;
		int len;
		int dir;
		vector<COORD> snakebody;
	public:
	    snake(COORD pos);
		COORD getpos();
		void setdir(int d);	
		void movesnake();
		bool collided();
		bool eaten(food &food);
		void grow();
		vector<COORD> getsnakebody();
			
};

#endif

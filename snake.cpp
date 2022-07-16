#include "snake.h"
#include<windows.h>
#define width 50
#define height 30
#include<vector>
using namespace std; 

snake::snake(COORD pos)
{
	this->pos =pos;
	len = 1;
	snakebody.push_back(pos);
}
COORD snake::getpos()
{
	return pos;
}
void snake::setdir(int d)
{
   dir = d;	
}
void snake::movesnake()
{
	switch(dir)
	{
		case 'u': pos.Y--;break;
		case 'd': pos.Y++;break;
		case 'l': pos.X--;break;
		case 'r': pos.X++;break;
		
	}
	snakebody.push_back(pos);
	if(snakebody.size() > len)
	{
		snakebody.erase(snakebody.begin());
	}
}
bool snake::collided()
{
	if(pos.X==0 || pos.Y==0 || pos.X==width+1 || pos.Y==height+1)
	{
		return true;
	}
	return false;
}
bool snake::eaten(food &food)
{
	if(pos.X==food.getfoodpos().X && pos.Y ==food.getfoodpos().Y)
	{
		return true;
	}
	return false;
}
void snake::grow()
{
	len++;
}
vector<COORD> snake::getsnakebody()
{
	return snakebody;
}
